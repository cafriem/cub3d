/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:56:22 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/10 18:38:48 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	check_door(t_cub3d *cube)
{
	if (cube->map.points[(int)(cube->player.p_y / 64
			- sin(deg2rad(cube->player.p_angle)))]
		[(int)(cube->player.p_x / 64
				- cos(deg2rad(cube->player.p_angle)))] == '2')
		door_msg(cube, "Press E to open", 369, 400);
	else if (cube->map.points[(int)(cube->player.p_y / 64
			- sin(deg2rad(cube->player.p_angle)))]
		[(int)(cube->player.p_x / 64
				- cos(deg2rad(cube->player.p_angle)))] == '3')
		return (door_msg(cube, "Press E to close", 367, 400));
}

void	door_msg(t_cub3d *cube, char *str, int x, int y)
{
	cube->hud.img = mlx_new_image(cube->mlx, 100, 20);
	cube->hud.addr = mlx_get_data_addr(cube->hud.img, &cube->hud.bpp,
			&cube->hud.line_length, &cube->hud.endian);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window,
		cube->hud.img, 364, 385);
	mlx_destroy_image(cube->mlx, cube->hud.img);
	mlx_string_put(cube->mlx, cube->mlx_window,
		x, y, 0x00FFFFFF, str);
}

void	open_door(t_cub3d *cube)
{
	if (cube->map.points[(int)(cube->player.p_y / 64
			- sin(deg2rad(cube->player.p_angle)))]
		[(int)(cube->player.p_x / 64
				- cos(deg2rad(cube->player.p_angle)))] == '2')
		cube->map.points[(int)(cube->player.p_y / 64
				- sin(deg2rad(cube->player.p_angle)))]
		[(int)(cube->player.p_x / 64
				- cos(deg2rad(cube->player.p_angle)))] = '3';
	else if (cube->map.points[(int)(cube->player.p_y / 64
			- sin(deg2rad(cube->player.p_angle)))]
		[(int)(cube->player.p_x / 64
				- cos(deg2rad(cube->player.p_angle)))] == '3')
		cube->map.points[(int)(cube->player.p_y / 64
				- sin(deg2rad(cube->player.p_angle)))]
		[(int)(cube->player.p_x / 64
				- cos(deg2rad(cube->player.p_angle)))] = '2';
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
	else if (keycode == E)
		open_door(cube);
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
