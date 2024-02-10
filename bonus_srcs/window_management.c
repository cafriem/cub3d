/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:52 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/10 14:42:40 by jadithya         ###   ########.fr       */
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
	free(cube->mlx);
	i = 0;
	while (i < 65)
	{
		free(cube->map.i_e[i]);
		free(cube->map.i_w[i]);
		free(cube->map.i_n[i]);
		free(cube->map.i_s[i]);
		free(cube->map.door[i]);
		free (cube->map.torch[0][i]);
		free (cube->map.torch[1][i]);
		free (cube->map.torch[2][i]);
		free (cube->map.torch[3][i]);
		free (cube->map.torch[4][i]);
		free (cube->map.torch[5][i]);
		i++;
	}
	free(cube->map.i_e);
	free(cube->map.i_w);
	free(cube->map.i_n);
	free(cube->map.i_s);
	free(cube->map.door);
	free (cube->map.torch[0]);
	free (cube->map.torch[1]);
	free (cube->map.torch[2]);
	free (cube->map.torch[3]);
	free (cube->map.torch[4]);
	free (cube->map.torch[5]);
	free (cube->map.torch);
	i = 0;
	while (cube->map.file_map[i])
		free (cube->map.file_map[i++]);
	free (cube->map.file_map);
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
