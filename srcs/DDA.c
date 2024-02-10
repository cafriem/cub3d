/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:03:16 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/06 17:12:27 by jadithya         ###   ########.fr       */
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
	while (i++ <= steps)
	{
		pixel_put(&cube->img, x1.x + (increase_x * (i - 1)), x1.y + (increase_y * (i - 1)),
			cube->map.i_n[(int)fabsf(text * (increase_t * (i - 1)))][(int)(cast->rayv.y * 4) % 64]);
	}
}

void	wall_text_v(t_point x1, t_point x2, t_cub3d *cube, t_cast *cast)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;
	float	increase_t;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
		steps = fabsf(x2.x - x1.x);
	else
		steps = fabsf(x2.y - x1.y);
	increase_x = (x2.x - x1.x) / steps;
	increase_y = (x2.y - x1.y) / steps;
	increase_t = 64 / steps;
	i = 0;
	while ((cast->r_angle > 90 && cast->r_angle < 270) && i++ <= steps)
	{
		if (x1.x + (increase_x * (i - 1)) >= 0 && x1.x + (increase_x * (i - 1)) < 800
			&&  x1.y + (increase_y * (i - 1)) >= 0 &&  x1.y + (increase_y * (i - 1)) < 800)
			pixel_put(&cube->img, x1.x + (increase_x * (i - 1)), x1.y + (increase_y * (i - 1)),
				cube->map.i_e[(int)fabsf(increase_t * (i - 1))][(int)(cast->rayv.y * 4) % 64]);
	}
	while (i++ <= steps)
	{
		if (x1.x + (increase_x * (i - 1)) >= 0 && x1.x + (increase_x * (i - 1)) < 800
			&&  x1.y + (increase_y * (i - 1)) >= 0 &&  x1.y + (increase_y * (i - 1)) < 800)
			pixel_put(&cube->img, x1.x + (increase_x * (i - 1)), x1.y + (increase_y * (i - 1)),
				cube->map.i_w[(int)fabsf(increase_t * (i - 1))][(int)(cast->rayv.y * 4) % 64]);
	}
}

void	wall_text_h(t_point x1, t_point x2, t_cub3d *cube, t_cast *cast)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;
	float	increase_t;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
		steps = fabsf(x2.x - x1.x);
	else
		steps = fabsf(x2.y - x1.y);
	increase_x = (x2.x - x1.x) / steps;
	increase_y = (x2.y - x1.y) / steps;
	increase_t = 64 / steps;
	i = 0;
	while ((cast->r_angle > 0 && cast->r_angle < 180) && i++ <= steps)
	{
		pixel_put(&cube->img, x1.x + (increase_x * (i - 1)), x1.y + (increase_y * (i - 1)),
			cube->map.i_s[(int)fabsf(increase_t * (i - 1))][(int)(cast->rayh.x * 4) % 64]);
	}
	while (i++ <= steps)
	{
		pixel_put(&cube->img, x1.x + (increase_x * (i - 1)), x1.y + (increase_y * (i - 1)),
			cube->map.i_n[(int)fabsf(increase_t * (i - 1))][(int)(cast->rayh.x * 4) % 64]);
	}
}
