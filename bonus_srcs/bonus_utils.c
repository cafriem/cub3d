/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:56:22 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/10 13:47:20 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	draw_hud(t_cub3d *cube)
{
	cube->hud.img = mlx_new_image(cube->mlx, cube->width, cube->height);
	cube->hud.addr = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, cube->hud.img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->hud.img);
}

int	keydown(int keycode, t_cub3d *cube)
{
	if (keycode == W)
		cube->dir.w = true;
	else if (keycode == A)
		cube->dir.a = true;
	else if (keycode == S)
		cube->dir.s = true;
	else if (keycode == D)
		cube->dir.d = true;
	else if (keycode == LEFT)
		cube->dir.left = true;
	else if (keycode == RIGHT)
		cube->dir.right = true;
	else if (keycode == SHIFT)
		cube->dir.shift = true;
	else if (keycode == M)
		cube->m = !cube->m;
	return (0);
}

int	keyup(int keycode, t_cub3d *cube)
{
	if (keycode == ESC)
		return (close_esc(keycode, cube));
	else if (keycode == W)
		cube->dir.w = false;
	else if (keycode == A)
		cube->dir.a = false;
	else if (keycode == S)
		cube->dir.s = false;
	else if (keycode == D)
		cube->dir.d = false;
	else if (keycode == LEFT)
		cube->dir.left = false;
	else if (keycode == RIGHT)
		cube->dir.right = false;
	else if (keycode == SHIFT)
		cube->dir.shift = false;
	return (0);
}
