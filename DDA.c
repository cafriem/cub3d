/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:03:16 by cafriem           #+#    #+#             */
/*   Updated: 2023/11/16 10:51:41 by cafriem          ###   ########.fr       */
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

// void	draw_point(t_data img, int linecount, int row)
// {
// 	float	dy;
// 	float	dx;
// 	float	c;
// 	int		i;

// 	dx = (img.x1 - img.x0);
// 	dy = (img.y1 - img.y0);
// 	if (fabs(dx) > fabs(dy))
// 		c = fabs(dx);
// 	else
// 		c = fabs(dy);
// 	i = 0;
// 	dx /= c;
// 	dy /= c;
// 	while (i <= c)
// 	{
// 		my_mlx_pixel_put(&img, img.x0, img.y0, img.colours[linecount][row]);
// 		img.y0 += dy;
// 		img.x0 += dx;
// 		i++;
// 	}
// }