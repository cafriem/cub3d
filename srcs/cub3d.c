/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:31:36 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/09 17:53:24 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	create_map(t_cub3d *cube)
{
	cube->width = 800;
	cube->height = 800;
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, cube->width, cube->height, "");
	draw_map(cube);
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
