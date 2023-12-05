/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:49 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/05 15:54:15 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	error(t_cub3d *cub3d, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("Failed : No File Name\n", 2);
		free (cub3d);
	}
	if (flag == 2)
	{
		ft_putstr_fd("Failed : Map wrong\n", 2);
		free (cub3d);
	}
	if (flag == 3)
	{
		ft_putstr_fd("Failed : Wrong number of players\n", 2);
		// free (cub3d);
	}
	exit(1);
}
