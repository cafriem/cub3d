/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:49 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/12 14:37:20 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	init(t_cub3d *cube)
{
	cube->map.points = NULL;
	cube->map.file_map = NULL;
	cube->map.t_n = NULL;
	cube->map.t_s = NULL;
	cube->map.t_e = NULL;
	cube->map.t_w = NULL;
	cube->map.i_n = NULL;
	cube->map.i_s = NULL;
	cube->map.i_e = NULL;
	cube->map.i_w = NULL;
	cube->map.door = NULL;
	cube->map.torch = NULL;
}

void	free_map(t_cub3d *cube)
{
	if (cube->map.points != NULL)
		ft_freesplit(cube->map.points);
	if (cube->map.file_map != NULL)
		ft_freesplit(cube->map.file_map);
}

void	error(t_cub3d *cube, int flag)
{
	if (flag == 0)
		exit (1);
	if (flag == 1)
		ft_putstr_fd("Error: No File Name\n", 2);
	if (flag == 2)
		ft_putstr_fd("Error: Map wrong\n", 2);
	if (flag == 3)
		ft_putstr_fd("Error: Wrong number of players\n", 2);
	if (flag == 4)
		ft_putstr_fd("Error: Ceiling or Floor, wrong color\n", 2);
	if (flag == 5)
		ft_putstr_fd("Error: Textures doesn't exist\n", 2);
	if (flag == 6)
		ft_putstr_fd("Error: Map has empty line\n", 2);
	if (flag == 7)
		ft_putstr_fd("Error: Map bad\n", 2);
	// free_map(cube);
	close_free(cube);
	exit(1);
}
