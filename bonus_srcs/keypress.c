/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:59:52 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 14:30:25 by jadithya         ###   ########.fr       */
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
		cube->player.p_angle = 359.9;
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
		cube->player.p_dx = -cos(deg2rad(cube->player.p_angle)) * 2;
		cube->player.p_dy = sin(deg2rad(cube->player.p_angle)) * 2;
	}
}

int	move(t_cub3d *cube)
{
	change_angle(cube);
	change_position(cube);
	if (cube->dir.w)
	{
		cube->player.p_x += cube->player.p_dx;
		cube->player.p_y += cube->player.p_dy;
	}
	if (cube->dir.s)
	{
		cube->player.p_x -= cube->player.p_dx;
		cube->player.p_y -= cube->player.p_dy;
	}
	if (cube->dir.a)
	{
		cube->player.p_x += cube->player.p_dy;
		cube->player.p_y -= cube->player.p_dx;
	}
	if (cube->dir.d)
	{
		cube->player.p_x -= cube->player.p_dy;
		cube->player.p_y += cube->player.p_dx;
	}
	draw_map(cube);
	return (0);
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
