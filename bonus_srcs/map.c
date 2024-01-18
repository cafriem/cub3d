/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:17 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/18 20:03:40 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

float	dist(t_point player, t_point ray, float angle)
{
	(void) angle;
	return (sqrt(
			((ray.x - player.x) * (ray.x - player.x))
			+ ((ray.y - player.y) * (ray.y - player.y))
		));
}

void	initialize_cast(t_cast *cast, t_cub3d *cube)
{
	cast->rays = 0;
	cast->r_angle = cube->player.p_angle - 30;
	if (cast->r_angle < 0)
		cast->r_angle += 360;
	cast->lines.x = 800;
	cast->lines.y = 0;
	cast->height.x = 800;
}

int	get_hex_color(t_cub3d *cube, int x, int y)
{
	int	i;
	int	colors[4];

	i = -1;
	while (++i < cube->doors.img.bpp / 8)
		colors[i] = (int) cube->doors.img.addr[((x * 4)
				+ (y * cube->doors.img.line_length)) + i];
	return (create_trgb(0, colors[2], colors[1], colors[0]));
}

void	draw_door(t_cub3d *cube, t_cast *cast)
{
	int	y;

	y = cast->lines.y;
	while (y < cast->height.y)
	{
		(void) cube;
		pixel_put(&cube->img, cast->height.x, y, get_hex_color(cube,
				(cast->height.x / 56),
				(cast->height.y - y) / 56));
		// printf("%d, %d\n", cast->lines.x % 56, ((cast->height.y - y) * 1 / 5));
		y++;
	}
}

void	door_or_wall(t_cub3d *cube, t_cast *cast)
{
	if (cast->distv <= cast->disth)
	{
		// if (cube->map.points[(int)(cast->rayv.y / 16)][(int)(cast->rayv.x / 16)] == '2')
		// 	draw_door(cube, cast);
		// else
		if (cube->map.points[(int)(cast->rayv.y / 16)][(int)(cast->rayv.x / 16)] != '2')
			dda(cast->height, cast->lines, cube, 0x005F6344);
	}
	else
	{
		// if (cube->map.points[(int)(cast->rayh.y / 16)][(int)cast->rayh.x / 16] == '2')
		// 	draw_door(cube, cast);
		// else
		if (cube->map.points[(int)(cast->rayh.y / 16)][(int)cast->rayh.x / 16] != '2')
			dda(cast->height, cast->lines, cube, 0x00A5633C);
	}
}

void	cast_n_project(t_cub3d *cube, t_cast *cast)
{
	if (cast->distv <= cast->disth)
		cast->distt = cast->distv;
	else
		cast->distt = cast->disth;
	cast->distt = cast->distt * cos(deg2rad(cast->angle_diff));
	cast->height.y = 64 * 400 / cast->distt;
	if (cast->height.y > 800)
		cast->height.y = 800;
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

// printf("p: %d, %d\nv: %d, %d (%f)\nh: %d, %d (%f)\n%f\n\n",
// 	player.x, player.y, rayv.x, rayv.y, distv,
// 	rayh.x, rayh.y, disth, cube->player.p_angle);

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

void	draw_map(t_cub3d *cube)
{
	int	i;
	int	j;

	cube->img.img = mlx_new_image(cube->mlx, cube->width, cube->height);
	cube->img.addr = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	draw_floor_ceiling(cube);
	i = -1;
	draw_rays(cube);
	while (cube->m && cube->map.points[++i])
	{
		j = -1;
		while (cube->map.points[i][++j])
		{
			if (cube->map.points[i][j] == '1')
				draw_square(i, j, cube, 0x00FFFFFF);
		}
	}
	if (cube->m)
		draw_player(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, cube->img.img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img.img);
	// mlx_put_image_to_window(cube->mlx, cube->mlx_window,
	// 	cube->doors.img.img, 400, 400);
	check_door(cube);
}
