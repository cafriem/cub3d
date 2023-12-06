/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:02:11 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/14 02:02:11 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cube.h"

void	dda(t_point x1, t_point x2, t_cub3d *cube, int color)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;

	if (abs(x2.x - x1.x) > abs(x2.y - x1.y))
	{
		steps = abs(x2.x - x1.x);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
	}
	else
	{
		steps = abs(x2.y - x1.y);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
	}
	i = 1;
	while (i++ <= steps)
		pixel_put(&cube->img, x1.x + (increase_x * (i - 1)),
			x1.y + (increase_y * (i - 1)),
			color);
}

void	loop_2(t_big *big)
{
	int		i;
	int		j;
	t_point	hold;

	j = -1;
	while (++j < big->array.y)
	{
		i = -1;
		while (++i < big->array.x)
		{
			angle_z(j * big->point.size, i * big->point.size, big);
			angle_x(j * big->point.size, i * big->point.size, big);
			angle_y(big);
			big->point.x += (big->img.x);
			big->point.y += (big->img.y);
			if (i > 0)
				dda(hold, big->point, big, set_color(i, j, big));
			hold.x = big->point.x;
			hold.y = big->point.y;
		}
	}
}

void	write_to_img(t_big *big)
{
	int		i;
	int		j;
	t_point	hold;

	i = -1;
	while (++i < big->array.x)
	{
		j = -1;
		while (++j < big->array.y)
		{
			angle_z(j * big->point.size, i * big->point.size, big);
			angle_x(j * big->point.size, i * big->point.size, big);
			angle_y(big);
			big->point.x += (big->img.x);
			big->point.y += (big->img.y);
			if (j > 0)
				dda(hold, big->point, big, set_color(i, j, big));
			hold.x = big->point.x;
			hold.y = big->point.y;
		}
	}
	loop_2(big);
}

int	str_color(char *str, t_big *big, int n, int j)
{
	int	i;

	i = 0;
	big->array.colors[n][j - 1] = ft_atohex(&str[i + 1]);
	i += 3;
	while (str[i] && (ft_isdigit(str[i]) || ishex(str[i])))
		i++;
	return (i);
}
