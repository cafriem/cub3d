/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:31:36 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/06 18:15:54 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_filemap(t_cub3d *cube)
{
	int	i;

	i = 0;
	while (cube->map.file_map[i])
	{
		if (i > 9)
			printf("%d: %s\n", i, cube->map.file_map[i]);
		else
			printf("%d : %s\n", i, cube->map.file_map[i]);
		i++;
	}
}

unsigned int	**t_ext(t_cub3d *cube, char *map)
{

	int	width;
	int	height;
	int	pos;
	cube->img.img = mlx_new_image(cube->mlx, cube->width, cube->height); // new image
	cube->img.img = mlx_xpm_file_to_image(cube->mlx, map, &width, &height); // mlx to image
	char	*name = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian); // getting the address of the image
	unsigned int	**num;
	int	x;
	int	y = 64;
	num = ft_calloc(65, sizeof(unsigned int *));
	while (y > -1)
	{
		x = 64;
		num[y] = ft_calloc(65, sizeof(unsigned int));
		while (x > -1)
		{
			pos = (y * cube->img.line_length + x * (cube->img.bpp / 8));
			num[y][x] = *(unsigned int *)&name[pos];
			x--;
		}
		y--;
	}
	mlx_destroy_image(cube->mlx, cube->img.img);
	return(num);
}

void	get_text(t_cub3d *cube)
{
	cube->map.i_n = t_ext(cube, cube->map.t_n);
	cube->map.i_s = t_ext(cube, cube->map.t_s);
	cube->map.i_e = t_ext(cube, cube->map.t_e);
	cube->map.i_w = t_ext(cube, cube->map.t_w);
}

int	main(int argc, char *argv[])
{
	t_cub3d	cube;

	if (argc != 2)
	{
		ft_putstr_fd("WRONG AMOUNT OF ARGUMENTS", 2);
		exit(1);
	}
	openmap(&cube, argv);
	set_booleans(&cube);
	create_map(&cube);
	print_filemap(&cube);
	mlx_hook(cube.mlx_window, 17, 0, close_x, &cube);
	mlx_hook(cube.mlx_window, 2, (1L << 0), keydown, &cube);
	mlx_hook(cube.mlx_window, 3, (1L << 1), keyup, &cube);
	mlx_loop_hook(cube.mlx, move, &cube);
	mlx_loop(cube.mlx);
}
