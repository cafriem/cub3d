/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:17 by jadithya          #+#    #+#             */
/*   Updated: 2023/12/06 16:43:36 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_x(int i, int j, t_cub3d *cube)
{
	int	a;
	int	b;

	a = j * 16;
	b = (j + 1) * 16;
	while (a < b)
	{
		pixel_put(&cube->img, a, i * 16, 0x00000000);
		a++;
	}
}

void	draw_y(int i, int j, t_cub3d *cube)
{
	int	a;
	int	b;

	a = i * 16;
	b = (i + 1) * 16;
	while (a < b)
	{
		pixel_put(&cube->img, j * 16, a, 0x00000000);
		a++;
	}
}

void	draw_square(int i, int j, t_cub3d *cube)
{
	int	a;
	int	b;
	int	hold;

	a = (i + 1) * 16;
	b = (j + 1) * 16;
	i *= 16;
	hold = j * 16;
	while (i < a - 1)
	{
		j = hold;
		while (j < b - 1)
		{
			pixel_put(&cube->img, j, i, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

void	draw_player(int i, int j, t_cub3d *cube)
{
	i = (16 * (i + (i + 1))) / 2;
	j = (16 * (j + (j + 1))) / 2;
	int c = i;
	int c2;
	while (c < i + 2)
	{
		c2 = j;
		while (c2 < j + 2)
		{
			pixel_put(&cube->img, c2, c, 0x00FF0000);
			c2++;
		}
		c++;
	}
}

void	draw_map(t_cub3d *cube)
{
	int	i;
	int	j;

	cube->img.img = mlx_new_image(cube->mlx, cube->width, cube->height);
	cube->img.addr = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	i = -1;
	while (cube->map.points[++i])
	{
		j = -1;
		while (cube->map.points[i][++j])
		{
			if (cube->map.points[i][j] == '1')
				draw_square(i, j, cube);
			else if (cube->map.points[i][j] != '0'
				&& cube->map.points[i][j] != ' ')
				draw_player(i, j, cube);
		}
	}
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, cube->img.img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img.img);
}

void	create_map(t_cub3d *cube)
{
	cube->width = 800;
	cube->height = 800;
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, cube->width, cube->height, "");
	draw_map(cube);
}
