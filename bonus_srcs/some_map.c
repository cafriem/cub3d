/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:33:54 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/10 22:34:58 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube_bonus.h"

void	print_filemap(t_cub3d *cube)
{
	int	i;

	i = 0;
	while (cube->map.file_map[i])
	{
		printf("%d: %s\n", i, cube->map.file_map[i]);
		i++;
	}
}

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
	if (ft_strcmp(ft_strchr(string, '.'), ".cub") == 0)
		return(1);
	return(0);
}
