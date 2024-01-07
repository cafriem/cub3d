/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:17 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/07 18:12:51 by jadithya         ###   ########.fr       */
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

void	set_horizontals(t_cub3d *cube, t_cast *cast)
{
	cast->player.x = cube->player.p_x;
	cast->player.y = cube->player.p_y;
	cast->dof = 0;
	if (cast->r_angle > 180)
	{
		cast->rayh.y = (((int) cube->player.p_y >> 6) << 6) - 0.0001;
		cast->rayh.x = (cube->player.p_y - cast->rayh.y)
			* (1 / tan(deg2rad(cast->r_angle))) + cube->player.p_x;
		cast->off.y = -64;
		cast->off.x = -cast->off.y * (1 / tan(deg2rad(cast->r_angle)));
		return ;
	}
	if ((int) cast->r_angle == 0 || (int) cast->r_angle == 180)
	{
		cast->rayh.x = cube->player.p_x;
		cast->rayh.y = cube->player.p_y;
		cast->dof = DOF;
		cast->disth = 100000;
		return ;
	}
	cast->rayh.y = (((int) cube->player.p_y >> 6) << 6) + 64;
	cast->rayh.x = ((cube->player.p_y - cast->rayh.y)
			* (1 / tan(deg2rad(cast->r_angle)))) + cube->player.p_x;
	cast->off.y = 64;
	cast->off.x = -cast->off.y * (1 / tan(deg2rad(cast->r_angle)));
}

void	set_rayh(t_cub3d *cube, t_cast *cast)
{
	while (cast->dof < DOF)
	{
		cast->disth = 100000;
		if (cast->rayh.y / 64 < cube->map.height && cast->rayh.y / 64 >= 0
			&& cast->rayh.x / 64 < cube->map.width && cast->rayh.x / 64 >= 0
			&& cube->map.points[cast->rayh.y / 64][cast->rayh.x / 64] == '1')
		{
			cast->disth = dist(cast->player, cast->rayh, cast->r_angle);
			cast->dof = DOF;
		}
		else
		{
			if (cube->player.p_angle == 0 || cube->player.p_angle == 180)
				break ;
			cast->rayh.x += cast->off.x;
			cast->rayh.y += cast->off.y;
		}
		cast->dof++;
	}
	if (cast->rayh.x <= 0)
		cast->rayh.x = 0;
	if (cast->rayh.y <= 0)
		cast->rayh.y = 0;
}

void	set_verticals(t_cub3d *cube, t_cast *cast)
{
	cast->dof = 0;
	if (cast->r_angle > 90 && cast->r_angle < 270)
	{
		cast->rayv.x = (((int) cube->player.p_x >> 6) << 6) + 64;
		cast->rayv.y = ((cube->player.p_x - cast->rayv.x)
				* (tan(deg2rad(cast->r_angle)))) + cube->player.p_y;
		cast->off.x = 64;
		cast->off.y = -cast->off.x * (tan(deg2rad(cast->r_angle)));
		return ;
	}
	if ((int) cast->r_angle == 90 || (int) cast->r_angle == 270)
	{
		cast->rayv.x = cube->player.p_x;
		cast->rayv.y = cube->player.p_y;
		cast->dof = DOF;
		cast->distv = 100000;
		return ;
	}
	cast->rayv.x = (((int) cube->player.p_x >> 6) << 6) - 0.0001;
	cast->rayv.y = ((cube->player.p_x - cast->rayv.x)
			* (tan(deg2rad(cast->r_angle)))) + cube->player.p_y;
	cast->off.x = -64;
	cast->off.y = -cast->off.x * (tan(deg2rad(cast->r_angle)));
}

void	set_rayv(t_cub3d *cube, t_cast *cast)
{
	while (cast->dof < DOF)
	{
		cast->distv = 100000;
		if (cast->rayv.x / 64 >= 0 && cast->rayv.y / 64 >= 0
			&& cast->rayv.y / 64 < cube->map.height
			&& cast->rayv.x / 64 < cube->map.width
			&& cube->map.points[cast->rayv.y / 64][cast->rayv.x / 64] == '1')
		{
			cast->distv = dist(cast->player, cast->rayv, cast->r_angle);
			cast->dof = DOF;
		}
		else
		{
			if (cube->player.p_angle == 90 || cube->player.p_angle == 270)
				break ;
			cast->rayv.x += cast->off.x;
			cast->rayv.y += cast->off.y;
			if (cast->rayv.x < 0)
				cast->rayv.x = 0;
			if (cast->rayv.y < 0)
				cast->rayv.y = 0;
		}
		cast->dof++;
	}
}

void	cast_n_project(t_cub3d *cube, t_cast *cast)
{
	if (cast->distv <= cast->disth)
		cast->distt = cast->distv;
	else
		cast->distt = cast->disth;
	cast->height.y = 64 * 400 / cast->distt;
	if (cast->height.y > 800)
		cast->height.y = 800;
	cast->lines.y = 400 - (cast->height.y / 2);
	cast->height.y += cast->lines.y;
	if (cast->distv <= cast->disth)
		dda(cast->height, cast->lines, cube, 0x00669999);
	else
		dda(cast->height, cast->lines, cube, 0x0044FF88);
	cast->height.x -= 1;
	cast->lines.x -= 1;
	if (cast->distv <= cast->disth)
		dda(cast->player, cast->rayv, cube, 0x0055FFFF);
	else
		dda(cast->player, cast->rayh, cube, 0x0055FFFF);
	cast->r_angle += 0.075;
	if (cast->r_angle < 0)
		cast->r_angle += 360;
	else if (cast->r_angle >= 360)
		cast->r_angle -= 360;
}

		// printf("p: %d, %d\nv: %d, %d (%f)\nh: %d, %d (%f)\n%f\n\n", player.x, player.y, rayv.x, rayv.y, distv, rayh.x, rayh.y, disth, cube->player.p_angle);

void	draw_rays(t_cub3d *cube)
{
	t_cast	cast;

	initialize_cast(&cast, cube);
	while (cast.rays++ < 800)
	{
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
