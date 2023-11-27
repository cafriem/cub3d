/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:49 by cafriem           #+#    #+#             */
/*   Updated: 2023/11/27 14:15:20 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	error(t_data *img, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("Failed : No File Name\n", 2);
		free (img);
	}
	if (flag == 2)
	{
		ft_putstr_fd("Failed : Map wrong\n", 2);
		free (img);
	}
	exit(1);
}
