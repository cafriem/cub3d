/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:25 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/12 14:31:06 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

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
	return (c1 - 1);
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

int	texture_parse2(t_cub3d *cub3d, char *line, int c)
{
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
		return (1);
	return (0);
}

void	nuggets(t_cub3d *cube)
{
	t_dir	bol;
	int		c;

	c = 0;
	bol.w = false;
	bol.a = false;
	bol.s = false;
	bol.d = false;
	while (cube->map.file_map[c] && c < 4)
	{
		bol.w = bol.w || (ft_strncmp(cube->map.file_map[c], "NO", 2) == 0);
		bol.a = bol.a || (ft_strncmp(cube->map.file_map[c], "SO", 2) == 0);
		bol.s = bol.s || (ft_strncmp(cube->map.file_map[c], "EA", 2) == 0);
		bol.d = bol.d || (ft_strncmp(cube->map.file_map[c], "WE", 2) == 0);
		c++;
	}
	if (!bol.w || !bol.a || !bol.s || !bol.d)
		error(cube, 5);
}

void	texture_parse(t_cub3d *cub3d)
{
	int		c;
	char	*line;

	c = -1;
	while (cub3d->map.file_map[++c])
	{
		line = ft_strtrim(cub3d->map.file_map[c], " ");
		if (texture_parse2(cub3d, line, c) == 1)
			break ;
		free (line);
	}
	if (line)
		free (line);
	if (cub3d->map.c == -1 || cub3d->map.f == -1)
		error(cub3d, 4);
	mapread(cub3d, c);
	nuggets(cub3d);
}
