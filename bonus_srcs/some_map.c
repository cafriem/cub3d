/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:33:54 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/12 14:05:16 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

int	mouse(int x, int y, t_cub3d *cube)
{
	(void) cube;
	(void) y;
	if (x < 400)
		cube->player.p_angle += 1;
	else if (x >= 400)
		cube->player.p_angle -= 1;
	if (cube->player.p_angle <= 0)
		cube->player.p_angle += 360;
	else if (cube->player.p_angle >= 360)
		cube->player.p_angle -= 360;
	return (0);
}

int	file_check(char *string)
{
	char	*str;

	str = ft_strchr(string, '.');
	if (str && ft_strcmp(str, ".cub") == 0)
		return (1);
	else
	{
		printf("Error: file invalid\n");
		exit(1);
	}
	return (0);
}
