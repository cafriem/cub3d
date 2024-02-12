/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:49 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/12 13:17:56 by jadithya         ###   ########.fr       */
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
		ft_putstr_fd("Error: No File Name\n", 2);
	if (flag == 2)
		ft_putstr_fd("Error: Map wrong\n", 2);
	if (flag == 3)
		ft_putstr_fd("Error: Wrong number of players\n", 2);
	if (flag == 4)
	{
		ft_putstr_fd("Error: Ceiling or Floor, wrong color\n", 2);
		if (cube->map.file_map)
			ft_freesplit(cube->map.file_map);
		exit(1);
	}
	if (flag == 5)
		ft_putstr_fd("Error: Textures doesn't exist\n", 2);
	if (flag == 6)
		ft_putstr_fd("Error: Map has empty line\n", 2);
	if (flag == 7)
		ft_putstr_fd("Error: Map bad\n", 2);
	free_map(cube);
	exit(1);
}
