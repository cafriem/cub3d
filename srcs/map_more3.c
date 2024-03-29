/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:18:13 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/12 17:32:08 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	set_booleans(t_cub3d *cube)
{
	cube->dir.w = false;
	cube->dir.s = false;
	cube->dir.a = false;
	cube->dir.d = false;
	cube->dir.left = false;
	cube->dir.right = false;
	cube->m = false;
	cube->dir.shift = false;
}

void	openmap(t_cub3d *cub3d, char *argv[])
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(cub3d, 1);
	str = readfile(fd);
	if (!str)
		error(cub3d, 8);
	cub3d->map.file_map = ft_split(str, '\n');
	free(str);
	texture_parse(cub3d);
	cub3d->player.p_x = cub3d->map.p_colom * 64 + 32;
	cub3d->player.p_y = cub3d->map.p_row * 64 + 32;
	cub3d->player.p_dx = cos(cub3d->player.p_angle) * 1;
	cub3d->player.p_dy = sin(cub3d->player.p_angle) * 1;
}
