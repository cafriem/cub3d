/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:43:50 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/18 19:58:54 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

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

void	draw_angle(t_cub3d *cube3d)
{
	float	dy;
	float	dx;
	float	c;
	int		i;

	dx = (cube3d->player.p_x - cube3d->player.p_dx);
	dy = (cube3d->player.p_y - cube3d->player.p_dy);
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
		pixel_put(&cube3d->img, cube3d->player.p_dx / 4,
			cube3d->player.p_dy / 4, 0x00FF0000);
		cube3d->player.p_dy += dy;
		cube3d->player.p_dx += dx;
		i++;
	}
}

void	draw_player(t_cub3d *cube3d)
{
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 - 1,
		cube3d->player.p_y / 4, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4,
		cube3d->player.p_y / 4 - 1, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 - 1,
		cube3d->player.p_y / 4 - 1, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 + 1,
		cube3d->player.p_y / 4 - 1, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 - 1,
		cube3d->player.p_y / 4 + 1, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4,
		cube3d->player.p_y / 4, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 + 1,
		cube3d->player.p_y / 4, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4,
		cube3d->player.p_y / 4 + 1, 0x00FF0000);
	pixel_put(&cube3d->img, cube3d->player.p_x / 4 + 1,
		cube3d->player.p_y / 4 + 1, 0x00FF0000);
	cube3d->player.p_dx += cube3d->player.p_x;
	cube3d->player.p_dy += cube3d->player.p_y;
	draw_angle(cube3d);
}

double	deg2rad(double degrees)
{
	return (degrees * (PIE / 180.0));
}

bool	is_wall(t_cub3d *cube, t_point ray)
{
	if (cube->map.points[(int)(ray.y / 16)][(int)(ray.x / 16)] == '1')
		return (true);
	return (false);
}
