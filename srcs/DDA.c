/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:03:16 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/25 16:37:49 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	dda(t_point x1, t_point x2, t_cub3d *cube, int color)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
	{
		steps = fabsf(x2.x - x1.x);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
	}
	else
	{
		steps = fabsf(x2.y - x1.y);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
	}
	i = 1;
	while (i++ <= steps)
		pixel_put(&cube->img, x1.x + (increase_x * (i - 1)),
			x1.y + (increase_y * (i - 1)),
			color);
}

void	wall_text(t_point x1, t_point x2, t_cub3d *cube, t_cast *cast)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;
	float	increase_t;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
	{
		steps = fabsf(x2.x - x1.x);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
		increase_t = 64 / steps;
	}
	else
	{
		steps = fabsf(x2.y - x1.y);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
		increase_t = 64 / steps;
	}
	i = 1;
	int	text = 1;
	printf ("x = %f, %f\n", cast->rayv.x, cast->rayv.y);
	while (i++ <= steps)
	{
		pixel_put(&cube->img, x1.x + (increase_x * (i - 1)), x1.y + (increase_y * (i - 1)),
			cube->map.i_n[(int)fabsf(text * (increase_t * (i - 1)))][(int)(cast->rayv.y * 4) % 64]);
	}
}
