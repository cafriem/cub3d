/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:25 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/10 14:30:32 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	player_info(t_cub3d *cub3d)
{
	char	*str;
	int		c;
	int		leter_count;

	c = 0;
	leter_count = 0;
	while (cub3d->map.points[c])
	{
		if (ft_strchr(cub3d->map.points[c], 'N') != NULL
			|| ft_strchr(cub3d->map.points[c], 'S') != NULL
			|| ft_strchr(cub3d->map.points[c], 'E') != NULL
			|| ft_strchr(cub3d->map.points[c], 'W') != NULL)
		{
			str = get_pl(cub3d, c, str);
			cub3d->map.p_row = c;
			cub3d->map.p_colom = ft_strlen(cub3d->map.points[c])
				- ft_strlen(str);
			leter_count++;
		}
		c++;
	}
	if (leter_count > 1)
		error(cub3d, 3);
}

void	texture_parse(t_cub3d *cub3d)
{
	int	c;

	c = -1;
	while (cub3d->map.file_map[++c])
	{
		if (ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "NO", 2) == 0)
			cub3d->map.t_n = ft_strchr(cub3d->map.file_map[c], '.');
		else if (!ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "SO", 2))
			cub3d->map.t_s = ft_strchr(cub3d->map.file_map[c], '.');
		else if (!ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "EA", 2))
			cub3d->map.t_e = ft_strchr(cub3d->map.file_map[c], '.');
		else if (!ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "WE", 2))
			cub3d->map.t_w = ft_strchr(cub3d->map.file_map[c], '.');
		else if (!ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "F", 1))
			cub3d->map.f = get_color(ft_substr((cub3d->map.file_map[c]), 1,
						ft_strlen(cub3d->map.file_map[c])));
		else if (!ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "C", 1))
			cub3d->map.c = get_color(ft_substr((cub3d->map.file_map[c]), 1,
						ft_strlen(cub3d->map.file_map[c])));
		else
			break ;
	}
	mapread(cub3d, c);
}

void	openmap(t_cub3d *cub3d, char *argv[])
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(cub3d, 1);
	cub3d->map.file_map = ft_split(readfile(fd), '\n');
	texture_parse(cub3d);
	// struck_check(cub3d);
	cub3d->player.p_x = cub3d->map.p_colom * 64 + 32;
	cub3d->player.p_y = cub3d->map.p_row * 64 + 32;
	cub3d->player.p_dx = cos(cub3d->player.p_angle) * 1;
	cub3d->player.p_dy = sin(cub3d->player.p_angle) * 1;
}

void	set_booleans(t_cub3d *cube)
{
	cube->dir.w = false;
	cube->dir.s = false;
	cube->dir.a = false;
	cube->dir.d = false;
	cube->dir.left = false;
	cube->dir.right = false;
	cube->m = false;
}
