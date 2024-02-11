/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:18:13 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/11 19:26:13 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

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

void	draw_hud(t_cub3d *cube)
{
	(void) cube;
}

void	openmap(t_cub3d *cub3d, char *argv[])
{
	int		fd;
	char	*str;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(cub3d, 1);
	str = readfile(fd);
	cub3d->map.file_map = ft_split(str, '\n');
	free(str);
	i = 0;
	while (cub3d->map.file_map[i])
	{
		// printf("%s\n", cub3d->map.file_map[i]);
		if (!ft_strlen(cub3d->map.file_map[i]))
			error(cub3d, 6);
		i++;
	}
	texture_parse(cub3d);
	cub3d->player.p_x = cub3d->map.p_colom * 64 + 32;
	cub3d->player.p_y = cub3d->map.p_row * 64 + 32;
	cub3d->player.p_dx = cos(cub3d->player.p_angle) * 1;
	cub3d->player.p_dy = sin(cub3d->player.p_angle) * 1;
}
