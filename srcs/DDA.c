/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:03:16 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/07 17:12:19 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
// 	int		window_width;
// 	int		window_height;

// 	window_height = 720;
// 	window_width = 1080;
// 	x += window_width / 2;
// 	y += window_height / 2;
// 	if ((x > 0 && y > 0) && (x < window_width && y < window_height))
// 	{
// 		dst = data->addr + (y * data->line_length + x
// 				* (data->bits_per_pixel / 8));
// 		*(unsigned int *)dst = color;
// 	}
// }

// void	draw_point(t_data cub3d, int linecount, int row)
// {
// 	float	dy;
// 	float	dx;
// 	float	c;
// 	int		i;

// 	dx = (cub3d.x1 - cub3d.x0);
// 	dy = (cub3d.y1 - cub3d.y0);
// 	if (fabs(dx) > fabs(dy))
// 		c = fabs(dx);
// 	else
// 		c = fabs(dy);
// 	i = 0;
// 	dx /= c;
// 	dy /= c;
// 	while (i <= c)
// 	{
// 		my_mlx_pixel_put(&cub3d, cub3d.x0, cub3d.y0, cub3d.colours[linecount][row]);
// 		cub3d.y0 += dy;
// 		cub3d.x0 += dx;
// 		i++;
// 	}
// }