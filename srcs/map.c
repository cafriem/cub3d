/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:17 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/24 19:16:25 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	cast_n_project(t_cub3d *cube, t_cast *cast)
{
	if (cast->distv <= cast->disth)
		cast->distt = cast->distv;
	else
		cast->distt = cast->disth;
	cast->distt = cast->distt * cos(deg2rad(cast->angle_diff));
	cast->height.y = 64 * 400 / cast->distt;
	// if (cast->height.y > 800)
	// 	cast->height.y = 800;
	cast->lines.y = 400 - (cast->height.y / 2);
	cast->height.y += cast->lines.y;
	if (cast->distv <= cast->disth)
		wall_text(cast->height, cast->lines, cube);
		// dda(cast->height, cast->lines, cube, 0x005F6344);
	else
		dda(cast->height, cast->lines, cube, 0x00A5633C);
		// wall_text(cast->height, cast->lines, cube);
	cast->height.x -= 1;
	cast->lines.x -= 1;
	if (cube->m && cast->distv <= cast->disth)
		dda(cast->player, cast->rayv, cube, 0x0055FFFF);
		// wall_text(cast->height, cast->lines, cube);
	else if (cube->m)
		dda(cast->player, cast->rayh, cube, 0x0055FFFF);
		// wall_text(cast->height, cast->lines, cube);
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

// void	draw_rays(t_cub3d *cube)
// {
// 	int	depth;
// 	int	ray_y;
// 	int	ray_x;
// 	int	x_off;
// 	int	y_off;


// 	depth = 0;
// 	ray_y = (cube->player.p_y / 16) * 16;
// 	ray_x = ((cube->player.p_y - ray_y)
// 			* (-1 / tan(cube->player.p_direction))) + cube->player.p_x;
// 	y_off = -64;
// 	x_off = -y_off * (-1 / tan(cube->player.p_direction));
// 	while (depth < 8)
// 	{

// 	}
// }

// int pos = (y * size_line + x * (bits_per_pixel / 8));

// unsigned int	**t_ext(t_cub3d *cube, char *map)
// {

// 	int	width;
// 	int	height;
// 	int	pos;
// 	cube->img.img = mlx_new_image(cube->mlx, cube->width, cube->height);
// 	cube->img.img = mlx_xpm_file_to_image(cube->mlx, map, &width, &height);
// 	char	*name = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
// 			&cube->img.line_length, &cube->img.endian);
// 	unsigned int	**num;
// 	int	x = 0;
// 	int	y = 0;
// 	num = ft_calloc(65, sizeof(unsigned int *));
// 	while (y < 64)
// 	{
// 		x = 0;
// 		num[y] = ft_calloc(65, sizeof(unsigned int));
// 		while (x < 64)
// 		{
// 			pos = (y * cube->img.line_length + x * (cube->img.bpp / 8));
// 			num[y][x] = *(unsigned int *)&name[pos];
// 			x++;
// 		}
// 		printf("part 3\n");
// 		y++;
// 	}
// 	printf("part 4\n");
// 	printf("part 5\n");
// 	return(num);
// }
// x = <------------>

// void	get_text(t_cub3d *cube)
// {
// 	cube->map.i_n = t_ext(cube, cube->map.t_n);
// 	cube->map.i_s = t_ext(cube, cube->map.t_s);
// 	cube->map.i_e = t_ext(cube, cube->map.t_e);
// 	cube->map.i_w = t_ext(cube, cube->map.t_w);
// }

void	draw_map(t_cub3d *cube)
{
	cube->img.img = mlx_new_image(cube->mlx, cube->width, cube->height);

	cube->img.addr = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);

	int	i;
	int	j;

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
}

void	create_map(t_cub3d *cube)
{
	cube->width = 800;
	cube->height = 800;
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, cube->width, cube->height, "");
	get_text(cube);
	draw_map(cube);
}
