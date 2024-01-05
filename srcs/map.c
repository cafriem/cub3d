/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:17 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/06 01:51:26 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_square(int i, int j, t_cub3d *cube, int color)
{
	int	a;
	int	b;
	int	hold;

	a = (i + 1) * 16;
	b = (j + 1) * 16;
	i *= 16;
	hold = j * 16;
	while (i < a)
	{
		j = hold;
		while (j < b)
		{
			if (i == a - 1 || j == b - 1)
				pixel_put(&cube->img, j, i, 0x00DDDDDD);
			else
				pixel_put(&cube->img, j, i, color);
			j++;
		}
		i++;
	}
}

double	deg2rad(double degrees)
{
	return (degrees * (PIE / 180.0));
}

void	draw_angle(t_cub3d *cube3d)
{
	float	dy;
	float	dx;
	float	c;
	int		i;

	dx = (cube3d->player.p_x - cube3d->player.p_dx);
	dy = (cube3d->player.p_y - cube3d->player.p_dy);
	// printf("issues: %f", cube3d->player.p_dx);
	// printf(", %f\n", cube3d->player.p_dy);
	if (fabs(dx) > fabs(dy))
		c = fabs(dx);
	else
		c = fabs(dy);
	i = 0;
	(void) i;
	dx /= c;
	dy /= c;
	while (i <= c)
	{
		pixel_put(&cube3d->img, cube3d->player.p_dx / 4, cube3d->player.p_dy / 4, 0x00FF0000);
		cube3d->player.p_dy += dy;
		cube3d->player.p_dx += dx;
		i++;
	}
}

void	draw_player(t_cub3d *cube3d)
{
	// printf("player pos: %f, %f, %f\n", cube3d->player.p_x / 4, cube3d->player.p_y / 4, cube3d->player.p_angle);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 - 1, cube3d->player.p_y / 4, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4, cube3d->player.p_y / 4 - 1, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 - 1, cube3d->player.p_y / 4 - 1, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 + 1, cube3d->player.p_y / 4 - 1, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 - 1, cube3d->player.p_y / 4 + 1, 0x00FF0000);

	pixel_put(&cube3d->img, cube3d->player.p_x / 4, cube3d->player.p_y / 4, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 + 1, cube3d->player.p_y / 4, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4, cube3d->player.p_y / 4 + 1, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 + 1, cube3d->player.p_y / 4 + 1, 0x00FF0000);
	cube3d->player.p_dx += cube3d->player.p_x;
	cube3d->player.p_dy += cube3d->player.p_y;
	draw_angle(cube3d);
}

bool	is_wall(t_cub3d *cube, t_point ray)
{
	// return (true);
	if (cube->player.p_angle <= -135 || cube->player.p_angle >= 135)
	{
		if (cube->map.points[(ray.y / 16)][(ray.x / 16)] == '1')
			return (true);
	}
	else if (cube->player.p_angle > -135 && cube->player.p_angle <= -45)
	{
		if (cube->map.points[(ray.y / 16)][(ray.x / 16)] == '1')
			return (true);
	}
	else if (cube->player.p_angle > -45 && cube->player.p_angle <= 45)
	{
		if (cube->map.points[(ray.y / 16)][(ray.x / 16)] == '1')
			return (true);
	}
	else
	{
		if (cube->map.points[(ray.y / 16)][(ray.x / 16)] == '1')
			return (true);
	}
	return (false);
}

float	dist(t_point player, t_point ray, float angle)
{
	(void) angle;
	// printf("angle: %f\n\n", angle);
	return (sqrt(
			((ray.x - player.x) * (ray.x - player.x))
			+ ((ray.y - player.y) * (ray.y - player.y))
		));
}

void	draw_rays(t_cub3d *cube)
{
	int		rays;
	int		dof;
	float	distv;
	float	disth;
	float	distt;
	float	r_angle;
	t_point	rayh;
	t_point	rayv;
	t_point	off;
	t_point	player;
	t_point	lines;
	t_point	height;

	rays = 0;
	r_angle = cube->player.p_angle - 30;
	if (r_angle < 0)
		r_angle += 360;
	lines.x = 800;
	lines.y = 0;
	height.x = 800;
	while (rays++ < 600)
	{
		player.x = cube->player.p_x;
		player.y = cube->player.p_y;
		dof = 0;
		if (r_angle > 180)
		{
			rayh.y = (((int) cube->player.p_y >> 6) << 6) - 0.0001;
			rayh.x = (cube->player.p_y - rayh.y) * (1 / tan(deg2rad(r_angle))) + cube->player.p_x;
			off.y = -64;
			off.x = -off.y * (1 / tan(deg2rad(r_angle)));
		}
		if ((int) r_angle == 0 || (int) r_angle == 180)
		{
			rayh.x = cube->player.p_x;
			rayh.y = cube->player.p_y;
			dof = DOF;
			disth = 100000;
		}
		if (r_angle < 180)
		{
			rayh.y = (((int) cube->player.p_y >> 6) << 6) + 64;
			rayh.x = ((cube->player.p_y - rayh.y) * (1 / tan(deg2rad(r_angle)))) + cube->player.p_x;
			off.y = 64;
			off.x = -off.y * (1 / tan(deg2rad(r_angle)));
		}
		while (dof < DOF)
		{
			disth = 100000;
			if (rayh.y / 64 < cube->map.height && rayh.y / 64 >= 0
				&& rayh.x / 64 < cube->map.width && rayh.x / 64 >= 0
				&& cube->map.points[rayh.y / 64][rayh.x / 64] == '1')
			{
				disth = dist(player, rayh, r_angle);
				dof = DOF;
			}
			else
			{
				rayh.x += off.x;
				rayh.y += off.y;
			}
			dof++;
		}
		if (rayh.x <= 0)
			rayh.x = 0;
		if (rayh.y <= 0)
			rayh.y = 0;
		dof = 0;
		if (r_angle > 90 && r_angle < 270)
		{
			rayv.x = (((int) cube->player.p_x >> 6) << 6) + 64;
			rayv.y = ((cube->player.p_x - rayv.x) * (tan(deg2rad(r_angle)))) + cube->player.p_y;
			off.x = 64;
			off.y = -off.x * (tan(deg2rad(r_angle)));
		}
		else if ((int) r_angle == 90 || (int) r_angle == 270)
		{
			rayv.x = cube->player.p_x;
			rayv.y = cube->player.p_y;
			dof = DOF;
			distv = 100000;
		}
		else
		{
			rayv.x = (((int) cube->player.p_x >> 6) << 6) - 0.0001;
			rayv.y = ((cube->player.p_x - rayv.x) * (tan(deg2rad(r_angle)))) + cube->player.p_y;
			off.x = -64;
			off.y = -off.x * (tan(deg2rad(r_angle)));
		}
		while (dof < DOF)
		{
			distv = 100000;
			if (rayv.x / 64 > 0 && rayv.y / 64 > 0
				&& rayv.y / 64 < cube->map.height
				&& rayv.x / 64 < cube->map.width
				&& cube->map.points[rayv.y / 64][rayv.x / 64] == '1')
			{
				distv = dist(player, rayv, r_angle);
				dof = DOF;
			}
			else
			{
				rayv.x += off.x;
				rayv.y += off.y;
				if (rayv.x < 0)
					rayv.x = 0;
				if (rayv.y < 0)
					rayv.y = 0;
			}
			dof++;
		}
		player.x /= 4;
		player.y /= 4;
		rayv.x /= 4;
		rayv.y /= 4;
		rayh.x /= 4;
		rayh.y /= 4;
		// printf("p: %d, %d\nv: %d, %d (%f)\nh: %d, %d (%f)\n%f\n\n", player.x, player.y, rayv.x, rayv.y, distv, rayh.x, rayh.y, disth, cube->player.p_angle);
		if (distv <= disth)
			distt = distv;
		else
			distt = disth;
		height.y = 64 * 400 / distt;
		if (height.y > 800)
			height.y = 800;
		lines.y = 400 - (height.y / 2);
		height.y += lines.y;
		dda(height, lines, cube, 0x00669999 + (20 * distt / 100));
		height.x -= 800 / 600;
		lines.x -= 800 / 600;
		if (distv <= disth)
			dda(player, rayv, cube, 0x0055FFFF);
		else
			dda(player, rayh, cube, 0x0055FFFF);
		r_angle += 0.1;
		if (r_angle < 0)
			r_angle += 360;
		else if (r_angle >= 360)
			r_angle -= 360;
	}
}

void	draw_map(t_cub3d *cube)
{
	int	i;
	int	j;

	cube->img.img = mlx_new_image(cube->mlx, cube->width, cube->height);
	cube->img.addr = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	i = -1;
	draw_rays(cube);
	while (cube->map.points[++i])
	{
		j = -1;
		while (cube->map.points[i][++j])
		{
			if (cube->map.points[i][j] == '1')
				draw_square(i, j, cube, 0x00FFFFFF);
		}
	}
	// printf("max pos: %d, %d\n", i * 16, j * 16);
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
	draw_map(cube);
}
