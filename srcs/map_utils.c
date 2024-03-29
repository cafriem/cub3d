/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:50 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/14 15:50:50 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_digit(char *string)
{
	int	c;

	c = 0;
	while (string[c])
	{
		if (!ft_isdigit(string[c]))
		{
			free(string);
			return (0);
		}
		c++;
	}
	free(string);
	return (1);
}

int	valid_letter(char letter)
{
	if (letter == '0' || letter == 'N' || letter == 'S' || letter == 'E'
		|| letter == 'W' || letter == ' ' || letter == '1')
		return (0);
	return (1);
}

void	check_updown(t_cub3d *cub3d, int row, int colom)
{
	int	vert;

	vert = row;
	while (cub3d->map.points[vert][colom] != '1')
	{
		vert--;
		if (vert < 0 || colom >= (int)ft_strlen(cub3d->map.points[vert])
			|| valid_letter(cub3d->map.points[vert][colom]) == 1)
			error(cub3d, 2);
	}
	vert = row;
	while (cub3d->map.points[vert][colom] != '1')
	{
		vert++;
		if (vert >= cub3d->map.height
			|| valid_letter(cub3d->map.points[vert][colom]) == 1)
			error(cub3d, 2);
	}
}

int	check_leftright(t_cub3d *cub3d, int row, int colom)
{
	int	hor;

	hor = colom;
	while (cub3d->map.points[row][hor] != '1')
	{
		hor--;
		if (hor < 0 || valid_letter(cub3d->map.points[row][hor]) == 1)
			error(cub3d, 2);
	}
	hor = colom;
	while (cub3d->map.points[row][hor] != '1')
	{
		hor++;
		if (hor >= cub3d->map.width
			|| valid_letter(cub3d->map.points[row][hor]) == 1)
			error(cub3d, 2);
	}
	return (1);
}
