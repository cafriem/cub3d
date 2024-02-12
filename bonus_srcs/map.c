/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:17 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/12 13:53:14 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	cast_n_project(t_cub3d *cube, t_cast *cast)
{
	if (cast->distv <= cast->disth)
		cast->distt = cast->distv;
	else
		cast->distt = cast->disth;
	cast->distt = cast->distt * cos(deg2rad(cast->angle_diff));
	cast->height.y = 64 * 400 / cast->distt;
	cast->lines.y = 400 - (cast->height.y / 2);
	cast->height.y += cast->lines.y;
	door_or_wall(cube, cast);
	cast->height.x -= 1;
	cast->lines.x -= 1;
	if (cube->m && cast->distv <= cast->disth)
		dda(cast->player, cast->rayv, cube, 0x0055FFFF);
	else if (cube->m)
		dda(cast->player, cast->rayh, cube, 0x0055FFFF);
	cast->r_angle += 0.075;
	if (cast->r_angle < 0)
		cast->r_angle += 360;
	else if (cast->r_angle >= 360)
		cast->r_angle -= 360;
}

void	draw_rays(t_cub3d *cube)
{
	t_cast	cast;

	initialize_cast(&cast, cube);
	while (cast.rays++ < 800)
	{
		cast.angle_diff = cube->player.p_angle - cast.r_angle;
		if (cast.angle_diff < 0)
			cast.angle_diff += 360;
		cast.player.x = cube->player.p_x;
		cast.player.y = cube->player.p_y;
		cast.dof = 0;
		set_horizontals(cube, &cast);
		set_rayh(cube, &cast);
		set_verticals(cube, &cast);
		set_rayv(cube, &cast);
		cast.player.x /= 4;
		cast.player.y /= 4;
		cast.rayv.x /= 4;
		cast.rayv.y /= 4;
		cast.rayh.x /= 4;
		cast.rayh.y /= 4;
		cast_n_project(cube, &cast);
	}
}

void	draw_torch(t_cub3d *cube, unsigned int **map)
{
	int		y;
	float	mapy;
	int		x;
	float	mapx;

	y = 600;
	mapy = 0;
	while (y < 800)
	{
		x = 600;
		mapx = 0;
		while (x < 800)
		{
			if (map && map[(int)mapy][(int)mapx])
				pixel_put(&cube->img, x, y, map[(int)mapy][(int)mapx]);
			mapx += 0.25;
			x++;
		}
		mapy += 0.25;
		y++;
	}
}

void	draw_map2(t_cub3d *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->m && cube->map.points[++i])
	{
		j = -1;
		while (cube->map.points[i][++j])
		{
			if (cube->map.points[i][j] == '1')
				draw_square(i, j, cube, 0x00FFFFFF);
			else if (cube->map.points[i][j] == '2'
				|| cube->map.points[i][j] == '3')
				draw_square(i, j, cube, 0x00822001);
		}
	}
}

void	draw_map(t_cub3d *cube)
{
	cube->img.img = mlx_new_image(cube->mlx, cube->width, cube->height);
	cube->img.addr = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	draw_floor_ceiling(cube);
	draw_rays(cube);
	draw_map2(cube);
	if (cube->m)
		draw_player(cube);
	cube->map.tnum++;
	if (cube->map.tnum > 5)
	{
		cube->map.tnum = 0;
		cube->map.torchnum++;
		if (cube->map.torchnum > 5)
			cube->map.torchnum = 0;
	}
	draw_torch(cube, cube->map.torch[cube->map.torchnum]);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, cube->img.img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img.img);
	check_door(cube);
}
