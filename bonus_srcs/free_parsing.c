/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:13:46 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/12 14:40:21 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	free_point(unsigned int **map)
{
	int	c;

	c = 0;
	while (c < 65)
	{
		free(map[c]);
		c++;
	}
	free(map);
}

void	free_torch(unsigned int ***torch)
{
	int	c;

	c = 0;
	while (c < 6)
	{
		free_point(torch[c]);
		c++;
	}
	free(torch);
}

void	close_free(t_cub3d *cube)
{
	// mlx_destroy_window(cube->mlx, cube->mlx_window);
	// free(cube->mlx);
	if (cube->map.i_e)
		free_point(cube->map.i_e);
	if (cube->map.i_w)
		free_point(cube->map.i_w);
	if (cube->map.i_n)
		free_point(cube->map.i_n);
	if (cube->map.i_s)
		free_point(cube->map.i_s);
	if (cube->map.door)
		free_point(cube->map.door);
	if (cube->map.points)
		ft_freesplit(cube->map.points);
	if (cube->map.file_map)
		ft_freesplit(cube->map.file_map);
	if (cube->map.torch)
		free_torch(cube->map.torch);
}
