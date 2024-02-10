/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:49 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/10 21:25:19 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	free_map(t_cub3d *cube)
{
	if (cube->map.points)
		ft_freesplit(cube->map.points);
	if (cube->map.file_map)
		ft_freesplit(cube->map.file_map);
}

void	error(t_cub3d *cube, int flag)
{
	if (flag == 0)
		exit (1);
	if (flag == 1)
	{
		ft_putstr_fd("Failed : No File Name\n", 2);
		free_map(cube);
	}
	if (flag == 2)
	{
		ft_putstr_fd("Failed : Map wrong\n", 2);
		free_map(cube);
	}
	if (flag == 3)
	{
		ft_putstr_fd("Failed : Wrong number of players\n", 2);
		free_map(cube);
	}
	if (flag == 4)
	{
		ft_putstr_fd("Failed : Ceiling or Floor, wrong color\n", 2);
		free_map(cube);
	}
	if (flag == 5)
	{
		ft_putstr_fd("Failed : Textures doesn't exist\n", 2);
		free_map(cube);
	}
	exit(1);
}
