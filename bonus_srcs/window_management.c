/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:52 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/26 00:11:45 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	close_free(t_cub3d *cube)
{
	int	i;

	mlx_destroy_window(cube->mlx, cube->mlx_window);
	i = 0;
	while (cube->map.points[i])
		free(cube->map.points[i++]);
	if (cube->map.points)
		free(cube->map.points);
}

int	close_x(t_cub3d *cube)
{
	close_free(cube);
	exit(0);
	return (0);
}

int	close_esc(int keycode, t_cub3d *cube)
{
	(void) keycode;
	close_free(cube);
	exit(0);
	return (0);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < 800 && y < 800))
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
