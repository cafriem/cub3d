/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:49 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 14:30:20 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

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
	}
	exit(1);
}
