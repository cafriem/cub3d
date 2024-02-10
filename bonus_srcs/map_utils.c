/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:50 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/10 13:49:36 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

char	*readfile(int fd)
{
	char	*ntext;
	char	*text;

	text = get_next_line(fd);
	ntext = get_next_line(fd);
	while (ntext != NULL)
	{
		text = ft_strjoinfree(text, ntext, 3);
		ntext = get_next_line(fd);
	}
	return (text);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_digit(char *string)
{
	int c;

	c = 0;
	while (string[c])
	{
		if (string[c] >= '0' && string[c] <= '9')
			return(1);
		c++;
	}
	return(0);
}

int	get_color(char *line)
{
	char	**spl;
	int		c;
	int		ret;

	spl = ft_split(line, ',');
	c = 0;
	while (spl[c])
		c++;
	if (c != 3)
		return (-1);
	if ((spl[0] && spl[1] && spl[2]) && (check_digit(spl[0]) == 1)
		&& (check_digit(spl[1]) == 1) && (check_digit(spl[2]) == 1))
		ret = create_trgb(1, ft_atoi(spl[0]), ft_atoi(spl[1]), ft_atoi(spl[2]));
	else
	{
		return (-1);
	}
	ft_freesplit(spl);
	if (line)
		free(line);
	return (ret);
}
void	check_updown(t_cub3d *cub3d, int row, int colom)
{
	int	vertical;

	vertical = row;
	while (cub3d->map.points[vertical][colom] != '1')
	{
		vertical--;
		if (vertical < 0)
			error(cub3d, 2);
	}
	vertical = row;
	while (cub3d->map.points[vertical][colom] != '1')
	{
		vertical++;
		if (vertical > cub3d->map.height)
			error(cub3d, 2);
	}
}

int	check_leftright(t_cub3d *cub3d, int row, int colom)
{
	int	horizontal;

	horizontal = colom;
	while (cub3d->map.points[row][horizontal] != '1')
	{
		horizontal--;
		if (horizontal < 0)
			error(cub3d, 2);
	}
	horizontal = colom;
	while (cub3d->map.points[row][horizontal] != '1')
	{
		horizontal++;
		if (horizontal > cub3d->map.width)
			error(cub3d, 2);
	}
	return (1);
}
