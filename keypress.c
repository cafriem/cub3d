/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:59:52 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/05 11:41:55 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	key_press1(int keypress, t_cub3d *cub3d)
// {
// 	mlx_clear_window(cub3d->mlx, cub3d->mlx_win);
// 	if (keypress == ESC)
// 	{
// 		mlx_destroy_window(cub3d->mlx, cub3d->mlx_win);
// 		free_points(cub3d);
// 		exit(0);
// 	}
	// if (keypress == H)
	// 	cub3d->help += 1;
	// if (keypress == PLUS)
	// {
	// 	cub3d->space += 1;
	// 	cub3d->height += 1;
	// }
	// if (keypress == MINUS)
	// {
	// 	cub3d->space -= 1;
	// 	cub3d->height -= 1;
	// }
	// if (keypress == UP)
	// 	cub3d->updown -= 2;
	// if (keypress == DOWN)
	// 	cub3d->updown += 2;
	// key_press2(keypress, cub3d);
	// return (0);
// }

// void	key_press2(int keypress, t_cub3d *cub3d)
// {
// 	if (keypress == LEFT)
// 		cub3d->leftright -= 2;
// 	if (keypress == RIGHT)
// 		cub3d->leftright += 2;
// 	if (keypress == R)
// 		cub3d->height += 1;
// 	if (keypress == F)
// 		cub3d->height -= 1;
// 	if (keypress == S)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->x += 5 * (PIE / 180.0f);
// 	}
// 	if (keypress == W)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->x -= 5 * (PIE / 180.0f);
// 	}
// 	key_press3(keypress, cub3d);
// }

// void	key_press3(int keypress, t_cub3d *cub3d)
// {
// 	if (keypress == D)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->y += 5 * (PIE / 180.0f);
// 	}
// 	if (keypress == A)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->y -= 5 * (PIE / 180.0f);
// 	}
// 	if (keypress == E)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->z += 5 * (PIE / 180.0f);
// 	}
// 	if (keypress == Q)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->z -= 5 * (PIE / 180.0f);
// 	}
// 	key_press4(keypress, cub3d);
// }

// void	key_press4(int keypress, t_cub3d *cub3d)
// {
// 	if (keypress == I)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->y = 0;
// 		cub3d->x = 1.482778;
// 		cub3d->z = 0.785000;
// 	}
// 	if (keypress == K)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->y = 0;
// 		cub3d->x = -0.348889;
// 		cub3d->z = 0.785000;
// 	}
// 	if (keypress == J)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->x = 0;
// 		cub3d->y = -0.348889;
// 		cub3d->z = -0.785000;
// 	}
// 	key_press5(keypress, cub3d);
// }

// void	key_press5(int keypress, t_cub3d *cub3d)
// {
// 	if (keypress == L)
// 	{
// 		cub3d->rotation = 1;
// 		cub3d->x = 0;
// 		cub3d->y = 0.348889;
// 		cub3d->z = 2.355000;
// 	}
// 	if (keypress == C)
// 		cub3d->colour = 0x00F3D6D3;
// 	mlx_destroy_image(cub3d->mlx, cub3d->cub3d);
// 	cub3d->cub3d = mlx_new_image(cub3d->mlx, 1080, 720);
// 	cub3d->addr = mlx_get_data_addr(cub3d->cub3d, &cub3d->bits_per_pixel,
// 			&cub3d->line_length, &cub3d->endian);
// 	points_on_grid(*cub3d);
// 	mlx_put_image_to_window(cub3d->mlx, cub3d->mlx_win, cub3d->cub3d, 0, 0);
// 	if (cub3d->help % 2 == 0)
// 		legends1(cub3d);
// }