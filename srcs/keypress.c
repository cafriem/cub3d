/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:59:52 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/20 18:53:20 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	move(t_cub3d *cube)
{
	if ((cube->dir.w && cube->dir.s) || (cube->dir.a && cube->dir.d))
		return (0);
	if (cube->dir.left)
		cube->player.p_angle -= 5;
	if (cube->dir.right)
		cube->player.p_angle += 5;
	cube->player.p_dx = cos(deg2rad(cube->player.p_angle)) * 64;
	cube->player.p_dy = sin(deg2rad(cube->player.p_angle)) * 64;
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
	printf("keydown: %d\n", keycode);
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
	move(cube);
	return (0);
}

int	keyup(int keycode, t_cub3d *cube)
{
	printf("keyup: %d\n", keycode);
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
	move(cube);
	return (0);
}

// int	key_press1(int keypress, t_data *img)
// {
// 	mlx_clear_window(img->mlx, img->mlx_win);
// 	if (keypress == ESC)
// 	{
// 		mlx_destroy_window(img->mlx, img->mlx_win);
// 		free_points(img);
// 		exit(0);
// 	}
	// if (keypress == H)
	// 	img->help += 1;
	// if (keypress == PLUS)
	// {
	// 	img->space += 1;
	// 	img->height += 1;
	// }
	// if (keypress == MINUS)
	// {
	// 	img->space -= 1;
	// 	img->height -= 1;
	// }
	// if (keypress == UP)
	// 	img->updown -= 2;
	// if (keypress == DOWN)
	// 	img->updown += 2;
	// key_press2(keypress, img);
	// return (0);
// }

// void	key_press2(int keypress, t_data *img)
// {
// 	if (keypress == LEFT)
// 		img->leftright -= 2;
// 	if (keypress == RIGHT)
// 		img->leftright += 2;
// 	if (keypress == R)
// 		img->height += 1;
// 	if (keypress == F)
// 		img->height -= 1;
// 	if (keypress == S)
// 	{
// 		img->rotation = 1;
// 		img->x += 5 * (PIE / 180.0f);
// 	}
// 	if (keypress == W)
// 	{
// 		img->rotation = 1;
// 		img->x -= 5 * (PIE / 180.0f);
// 	}
// 	key_press3(keypress, img);
// }

// void	key_press3(int keypress, t_data *img)
// {
// 	if (keypress == D)
// 	{
// 		img->rotation = 1;
// 		img->y += 5 * (PIE / 180.0f);
// 	}
// 	if (keypress == A)
// 	{
// 		img->rotation = 1;
// 		img->y -= 5 * (PIE / 180.0f);
// 	}
// 	if (keypress == E)
// 	{
// 		img->rotation = 1;
// 		img->z += 5 * (PIE / 180.0f);
// 	}
// 	if (keypress == Q)
// 	{
// 		img->rotation = 1;
// 		img->z -= 5 * (PIE / 180.0f);
// 	}
// 	key_press4(keypress, img);
// }

// void	key_press4(int keypress, t_data *img)
// {
// 	if (keypress == I)
// 	{
// 		img->rotation = 1;
// 		img->y = 0;
// 		img->x = 1.482778;
// 		img->z = 0.785000;
// 	}
// 	if (keypress == K)
// 	{
// 		img->rotation = 1;
// 		img->y = 0;
// 		img->x = -0.348889;
// 		img->z = 0.785000;
// 	}
// 	if (keypress == J)
// 	{
// 		img->rotation = 1;
// 		img->x = 0;
// 		img->y = -0.348889;
// 		img->z = -0.785000;
// 	}
// 	key_press5(keypress, img);
// }

// void	key_press5(int keypress, t_data *img)
// {
// 	if (keypress == L)
// 	{
// 		img->rotation = 1;
// 		img->x = 0;
// 		img->y = 0.348889;
// 		img->z = 2.355000;
// 	}
// 	if (keypress == C)
// 		img->colour = 0x00F3D6D3;
// 	mlx_destroy_image(img->mlx, img->img);
// 	img->img = mlx_new_image(img->mlx, 1080, 720);
// 	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
// 			&img->line_length, &img->endian);
// 	points_on_grid(*img);
// 	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
// 	if (img->help % 2 == 0)
// 		legends1(img);
// }

