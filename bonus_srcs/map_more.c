/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:25 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/10 14:06:18 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	draw_hud(t_cub3d *cube)
{
	(void) cube;
}

int	player_check(t_cub3d *cub3d, int c)
{
	int	c1;

	c1 = 0;
	if (ft_strchr(cub3d->map.points[c], 'N') != NULL)
		c1++;
	if (ft_strchr(cub3d->map.points[c], 'S') != NULL)
		c1++;
	if (ft_strchr(cub3d->map.points[c], 'E') != NULL)
		c1++;
	if (ft_strchr(cub3d->map.points[c], 'W') != NULL)		
		c1++;
	return(c1 - 1);
}

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
			leter_count += player_check(cub3d, c);
			leter_count++;
		}
		c++;
	}
	if (leter_count > 1)
		error(cub3d, 3);
}

void	checker(t_cub3d *cube)
{
	if (cube->map.c == -1 || cube->map.c == -1)
		error(cube, 4);
}

void	texture_parse(t_cub3d *cub3d)
{
	int		c;
	char	*line;

	c = -1;
	while (cub3d->map.file_map[++c])
	{
		line = ft_strtrim(cub3d->map.file_map[c], " ");
		if (ft_strncmp(line, "NO", 2) == 0)
			cub3d->map.t_n = ft_strchr(cub3d->map.file_map[c], '.');
		else if (!ft_strncmp(line, "SO", 2))
			cub3d->map.t_s = ft_strchr(cub3d->map.file_map[c], '.');
		else if (!ft_strncmp(line, "EA", 2))
			cub3d->map.t_e = ft_strchr(cub3d->map.file_map[c], '.');
		else if (!ft_strncmp(line, "WE", 2))
			cub3d->map.t_w = ft_strchr(cub3d->map.file_map[c], '.');
		else if (!ft_strncmp(line, "F", 1))
			cub3d->map.f = get_color(ft_substr((cub3d->map.file_map[c]), 1,
						ft_strlen(cub3d->map.file_map[c])));
		else if (!ft_strncmp(line, "C", 1))
			cub3d->map.c = get_color(ft_substr((cub3d->map.file_map[c]), 1,
						ft_strlen(cub3d->map.file_map[c])));
		else
			break ;
		free (line);
	}
	checker(cub3d);
	mapread(cub3d, c);
}

void	openmap(t_cub3d *cub3d, char *argv[])
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(cub3d, 1);
	str = readfile(fd);
	cub3d->map.file_map = ft_split(str, '\n');
	free(str);
	texture_parse(cub3d);
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
	cube->dir.shift = false;
}
