/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:17 by jadithya          #+#    #+#             */
/*   Updated: 2023/12/17 12:59:29 by jadithya         ###   ########.fr       */
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
	printf("issues: %f", cube3d->player.p_x);
	printf(", %f\n", cube3d->player.p_dx);
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

void	draw_rays(t_cub3d *cube)
{
	int		depth;
	int		ray_y;
	int		ray_x;
	int		x_off;
	int		y_off;
	t_point	player;
	t_point	rayend;

	depth = 0;
	ray_y = (cube->player.p_y / 64);
	ray_x = ((cube->player.p_y / 64 - ray_y)
			* (-1 / tan(cube->player.p_direction))) + cube->player.p_x / 64;
	y_off = -64;
	x_off = -y_off * (-1 / tan(cube->player.p_direction));
	(void) x_off;
	(void) depth;
	// while (depth < 8)
	// {

	// }
	player.x = cube->player.p_y;
	player.y = cube->player.p_x;
	rayend.x = ray_y;
	rayend.y = ray_x;
	printf("raypoints: %d, %d\n", rayend.x, rayend.y);
	dda(player, rayend, cube, 0x000000FF);
}

void	draw_map(t_cub3d *cube)
{
	int	i;
	int	j;

	cube->img.img = mlx_new_image(cube->mlx, cube->width, cube->height);
	cube->img.addr = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	i = -1;
	while (cube->map.points[++i])
	{
		j = -1;
		while (cube->map.points[i][++j])
		{
			if (cube->map.points[i][j] == '1')
				draw_square(i, j, cube, 0x00FFFFFF);
		}
	}
	printf("max pos: %d, %d\n", i * 16, j * 16);
	draw_player(cube);
	draw_rays(cube);
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
