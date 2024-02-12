/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:31:36 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/12 15:31:51 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

unsigned int	**t_ext(t_cub3d *cube, char *map, int x, int y)
{
	int				width;
	int				height;
	int				pos;
	char			*name;
	unsigned int	**num;

	cube->img.img = mlx_xpm_file_to_image(cube->mlx, map, &width, &height);
	name = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	num = ft_calloc(65, sizeof(unsigned int *));
	y = 64;
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
	return (num);
}

void	check_text(t_cub3d *cube)
{
	if (access(cube->map.t_n, F_OK | R_OK) == -1
		|| access(cube->map.t_s, F_OK | R_OK) == -1
		|| access(cube->map.t_w, F_OK | R_OK) == -1
		|| access(cube->map.t_e, F_OK | R_OK) == -1
		|| access("textures/doors.xpm", F_OK | R_OK) == -1
		|| access("textures/Torch_1.xpm", F_OK | R_OK) == -1
		|| access("textures/Torch_2.xpm", F_OK | R_OK) == -1
		|| access("textures/Torch_3.xpm", F_OK | R_OK) == -1
		|| access("textures/Torch_4.xpm", F_OK | R_OK) == -1
		|| access("textures/Torch_5.xpm", F_OK | R_OK) == -1
		|| access("textures/Torch_6.xpm", F_OK | R_OK) == -1)
	{
		mlx_destroy_window(cube->mlx, cube->mlx_window);
		free(cube->mlx);
		error(cube, 5);
	}
}

void	get_text(t_cub3d *cube)
{
	check_text(cube);
	cube->map.i_n = t_ext(cube, cube->map.t_n, 64, 64);
	cube->map.i_s = t_ext(cube, cube->map.t_s, 64, 64);
	cube->map.i_e = t_ext(cube, cube->map.t_e, 64, 64);
	cube->map.i_w = t_ext(cube, cube->map.t_w, 64, 64);
	cube->map.door = t_ext(cube, "textures/doors.xpm", 64, 64);
	cube->map.torch = calloc(6, sizeof(unsigned int **));
	cube->map.torch[0] = t_ext(cube, "textures/Torch_1.xpm", 64, 64);
	cube->map.torch[1] = t_ext(cube, "textures/Torch_3.xpm", 64, 64);
	cube->map.torch[2] = t_ext(cube, "textures/Torch_4.xpm", 64, 64);
	cube->map.torch[3] = t_ext(cube, "textures/Torch_5.xpm", 64, 64);
	cube->map.torch[4] = t_ext(cube, "textures/Torch_6.xpm", 64, 64);
	cube->map.torch[5] = t_ext(cube, "textures/Torch_1.xpm", 64, 64);
}

void	create_map(t_cub3d *cube)
{
	cube->width = 800;
	cube->height = 800;
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, cube->width, cube->height, "");
	get_text(cube);
	draw_map(cube);
}

int	main(int argc, char *argv[])
{
	t_cub3d	cube;

	if (argc != 2 || file_check(argv[1]) != 1)
	{
		ft_putstr_fd("Error: WRONG AMOUNT OF ARGUMENTS", 2);
		exit(1);
	}
	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		error(&cube, 0);
	init(&cube);
	cube.map.tnum = 0;
	cube.map.torchnum = 0;
	openmap(&cube, argv);
	set_booleans(&cube);
	create_map(&cube);
	mlx_hook(cube.mlx_window, 17, 0, close_x, &cube);
	mlx_hook(cube.mlx_window, 2, 1L << 0, keydown, &cube);
	mlx_hook(cube.mlx_window, 3, (1L << 1), keyup, &cube);
	mlx_hook(cube.mlx_window, 6, (1L << 6), mouse, &cube);
	mlx_loop_hook(cube.mlx, move, &cube);
	mlx_loop(cube.mlx);
}
