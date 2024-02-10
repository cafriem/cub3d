/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:52 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/10 23:14:17 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

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
