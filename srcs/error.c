/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:49 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/11 18:32:12 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	error(t_cub3d *cub3d, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("Error: No File Name\n", 2);
		free (cub3d);
	}
	if (flag == 2)
	{
		ft_putstr_fd("Error: Map wrong\n", 2);
		free (cub3d);
	}
	if (flag == 3)
	{
		ft_putstr_fd("Error: Wrong number of players\n", 2);
	}
	exit(1);
}
