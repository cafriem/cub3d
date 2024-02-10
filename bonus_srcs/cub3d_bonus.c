/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:31:36 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/10 14:23:08 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

// void	print_map(t_cub3d *cub3d)
// {
// 	int	c;

// 	c = 0;
// 	while (cub3d->map.points[c])
// 	{
// 		if (c > 9)
// 			printf("mapline = %d |%s|\n", c, cub3d->map.points[c]);
// 		else
// 			printf("mapline = %d  |%s|\n", c, cub3d->map.points[c]);
// 		c++;
// 	}
// }

// void	struck_check(t_cub3d *cub3d)
// {
// 	printf("NO texture = %s\n", cub3d->map.t_n);
// 	printf("SO texture = %s\n", cub3d->map.t_s);
// 	printf("EA texture = %s\n", cub3d->map.t_e);
// 	printf("WE texture = %s\n", cub3d->map.t_w);
// 	printf("F = %d\n", cub3d->map.f);
// 	printf("C = %d\n", cub3d->map.c);
// 	printf("player facing = %f\n", cub3d->player.p_angle);
// 	printf("player location = %d, %d\n", cub3d->map.p_row, cub3d->map.p_colom);
// }

void	print_filemap(t_cub3d *cube)
{
	int	i;

	i = 0;
	while (cube->map.file_map[i])
	{
		printf("%d: %s\n", i, cube->map.file_map[i]);
		i++;
	}
}

unsigned int	**t_ext(t_cub3d *cube, char *map)
{

	int	width;
	int	height;
	int	pos;
	cube->img.img = mlx_xpm_file_to_image(cube->mlx, map, &width, &height);
	char	*name = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
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

void	check_text(t_cub3d *cube)
{
	if (access(cube->map.t_n, F_OK) == -1 || access(cube->map.t_n, R_OK) == -1)
		error(cube, 5);
	if (access(cube->map.t_s, F_OK) == -1 || access(cube->map.t_s, R_OK) == -1)
		error(cube, 5);
	if (access(cube->map.t_e, F_OK) == -1 || access(cube->map.t_e, R_OK) == -1)
		error(cube, 5);
	if (access(cube->map.t_w, F_OK) == -1 || access(cube->map.t_w, R_OK) == -1)
		error(cube, 5);
	if (access("textures/doors.xpm", F_OK) == -1 || access("textures/doors.xpm", R_OK) == -1)
		error(cube, 5);
	if (access("textures/Torch_1.xpm", F_OK) == -1 || access("textures/Torch_1.xpm", R_OK) == -1)
		error(cube, 5);
	if (access("textures/Torch_2.xpm", F_OK) == -1 || access("textures/Torch_2.xpm", R_OK) == -1)
		error(cube, 5);
	if (access("textures/Torch_3.xpm", F_OK) == -1 || access("textures/Torch_3.xpm", R_OK) == -1)
		error(cube, 5);
	if (access("textures/Torch_4.xpm", F_OK) == -1 || access("textures/Torch_4.xpm", R_OK) == -1)
		error(cube, 5);
	if (access("textures/Torch_5.xpm", F_OK) == -1 || access("textures/Torch_5.xpm", R_OK) == -1)
		error(cube, 5);
	if (access("textures/Torch_6.xpm", F_OK) == -1 || access("textures/Torch_6.xpm", R_OK) == -1)
		error(cube, 5);
}

void	get_text(t_cub3d *cube)
{
	check_text(cube);
	cube->map.i_n = t_ext(cube, cube->map.t_n);
	cube->map.i_s = t_ext(cube, cube->map.t_s);
	cube->map.i_e = t_ext(cube, cube->map.t_e);
	cube->map.i_w = t_ext(cube, cube->map.t_w);
	cube->map.door = t_ext(cube, "textures/doors.xpm");

	cube->map.torch = calloc(6, sizeof(unsigned int **));
	cube->map.torch[0] = t_ext(cube, "textures/Torch_1.xpm");
	cube->map.torch[1] = t_ext(cube, "textures/Torch_2.xpm");
	cube->map.torch[2] = t_ext(cube, "textures/Torch_3.xpm");
	cube->map.torch[3] = t_ext(cube, "textures/Torch_4.xpm");
	cube->map.torch[4] = t_ext(cube, "textures/Torch_5.xpm");
	cube->map.torch[5] = t_ext(cube, "textures/Torch_6.xpm");
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

int	mouse(int x, int y, t_cub3d *cube)
{
	(void) cube;
	(void) y;
	if (x < 400)
		cube->player.p_angle += 1;
	else if (x >= 400)
		cube->player.p_angle -= 1;
	if (cube->player.p_angle <= 0)
		cube->player.p_angle += 360;
	else if (cube->player.p_angle >= 360)
		cube->player.p_angle -= 360;
	return (0);
}

int	file_check(char *string)
{
	if (ft_strcmp(ft_strchr(string, '.'), ".cub") == 0)
		return(1);
	return(0);
}

int	main(int argc, char *argv[])
{
	t_cub3d	cube;

	if (argc != 2 || file_check(argv[1]) != 1)
	{
		ft_putstr_fd("WRONG AMOUNT OF ARGUMENTS", 2);
		exit(1);
	}
	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		error(&cube, 0);
	cube.map.tnum = 0;
	cube.map.torch = 0;
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
