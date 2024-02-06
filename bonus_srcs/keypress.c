/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:59:52 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/06 16:22:56 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	change_angle(t_cub3d *cube)
{
	if (cube->dir.left)
		cube->player.p_angle += 1;
	if (cube->dir.right)
		cube->player.p_angle -= 1;
	if (cube->player.p_angle < 0)
		cube->player.p_angle = 360;
	else if (cube->player.p_angle >= 360)
		cube->player.p_angle = 0;
}

void	change_position(t_cub3d *cube)
{
	if (!cube->dir.shift)
	{
		cube->player.p_dx = -cos(deg2rad(cube->player.p_angle)) * 1;
		cube->player.p_dy = sin(deg2rad(cube->player.p_angle)) * 1;
	}
	else
	{
		cube->player.p_dx = (-cos(deg2rad(cube->player.p_angle))) * 3;
		cube->player.p_dy = (sin(deg2rad(cube->player.p_angle))) * 3;
	}
}

int	keydown(int keycode, t_cub3d *cube)
{
	write(1, "hi\n", 3);
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
	else if (keycode == E)
		open_door(cube);
	return (0);
}

int	keyup(int keycode, t_cub3d *cube)
{
	printf("key: %d\n", keycode);
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
