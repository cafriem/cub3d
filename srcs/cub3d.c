/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:31:36 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/07 18:35:13 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <complex.h>

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

int	get_color(char *line)
{
	char	**spl;
	int		ret;

	spl = ft_split(line, ',');
	ret = create_trgb(1, ft_atoi(spl[0]), ft_atoi(spl[1]), ft_atoi(spl[2]));
	ft_freesplit(spl);
	return (ret);
}

void	check_updown(t_cub3d *cub3d, int row, int colom)
{
	int	vertical;

	vertical = row;
	while (cub3d->map.points[vertical][colom] != '1') //checks up
	{
		vertical--;
		if (vertical < 0)
			error(cub3d, 2);
	}
	vertical = row;
	while (cub3d->map.points[vertical][colom] != '1') //checks down
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
	while (cub3d->map.points[row][horizontal] != '1') //checks left
	{
		horizontal--;
		if (horizontal < 0)
			error(cub3d, 2);
	}
	horizontal = colom;
	while (cub3d->map.points[row][horizontal] != '1') //checks right
	{
		horizontal++;
		if (horizontal > cub3d->map.width)
			error(cub3d, 2);
	}
	return (1);
}

void	check_valid(t_cub3d *cub3d, int row, int colom)
{
	check_updown(cub3d, row, colom);
	check_leftright(cub3d, row, colom);
}

void	map_checker(t_cub3d *cub3d)
{
	int	row;
	int	colom;

	row = 0;
	while (cub3d->map.points[row])
	{
		colom = 0;
		while (cub3d->map.points[row][colom])
		{
			if (cub3d->map.points[row][colom] == '0')
				check_valid(cub3d, row, colom);
			colom++;
		}
		row++;
	}
}

void	map_size(t_cub3d *cub3d)
{
	int	c;
	int	c1;

	c = 0;
	c1 = 0;
	c1 = ft_strlen(cub3d->map.points[c]);
	while (cub3d->map.points[c])
	{
		if ((int)ft_strlen(cub3d->map.points[c]) > c1)
			c1 = ft_strlen(cub3d->map.points[c]);
		c++;
	}
	cub3d->map.width = c1;
	cub3d->map.height = c;
}

char	*get_pl(t_cub3d *cub3d, int c)
{
	int		counter;
	char	*str;

	counter = 0;
	if (ft_strchr(cub3d->map.points[c], 'N') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'N');
		cub3d->player.p_angle = 0;
		counter++;
	}
	if (ft_strchr(cub3d->map.points[c], 'S') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'S');
		cub3d->player.p_angle = 180;
		counter++;
	}
	if (ft_strchr(cub3d->map.points[c], 'E') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'E');
		cub3d->player.p_angle = 90;
		counter++;
	}
	if (ft_strchr(cub3d->map.points[c], 'W') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'W');
		cub3d->player.p_angle = 270;
		counter++;
	}
	if (counter > 1 || (counter == 1 && (ft_strlen(str) != ft_strlen(ft_strrchr(str, str[0])))))
		error(cub3d, 3);
	return (str);
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
		if (ft_strchr(cub3d->map.points[c], 'N') != NULL || ft_strchr(cub3d->map.points[c], 'S') != NULL
			|| ft_strchr(cub3d->map.points[c], 'E') != NULL || ft_strchr(cub3d->map.points[c], 'W') != NULL)
		{
			str = get_pl(cub3d, c);
			cub3d->map.p_row = c;
			cub3d->map.p_colom = ft_strlen(cub3d->map.points[c]) - ft_strlen(str);
			leter_count++;
		}
		c++;
	}
	if (leter_count > 1)
		error(cub3d, 3);
}

void	mapread(t_cub3d *cub3d, int start)
{
	int		c;
	char	*str;

	c = start;
	str = ft_strdup(cub3d->map.file_map[c]);
	while (cub3d->map.file_map[c + 1])
	{
		c++;
		str = ft_strjoin(str, "\n");
		str = ft_strjoin(str, cub3d->map.file_map[c]);
	}
	str = ft_strtrim_free(str, "\n");
	cub3d->map.points = ft_split(str, '\n');
	map_size(cub3d);
	map_checker(cub3d);
	player_info(cub3d);
}

void	texture_parse(t_cub3d *cub3d)
{
	int	c;
	int	c1;

	c = 0;
	c1 = 0;
	while (cub3d->map.file_map[c])
	{
		if (ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "NO", 2) == 0)
		{
			cub3d->map.t_n = ft_strchr(cub3d->map.file_map[c], '.');
			c1++;
		}
		if (ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "SO", 2) == 0)
		{
			cub3d->map.t_s = ft_strchr(cub3d->map.file_map[c], '.');
			c1++;
		}
		if (ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "EA", 2) == 0)
		{
			cub3d->map.t_e = ft_strchr(cub3d->map.file_map[c], '.');
			c1++;
		}
		if (ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "WE", 2) == 0)
		{
			cub3d->map.t_w = ft_strchr(cub3d->map.file_map[c], '.');
			c1++;
		}
		if (ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "F", 1) == 0)
		{
			cub3d->map.f = get_color(ft_substr((cub3d->map.file_map[c]), 1, ft_strlen(cub3d->map.file_map[c])));
			c1++;
		}
		if (ft_strncmp(ft_strtrim(cub3d->map.file_map[c], " "), "C", 1) == 0)
		{
			cub3d->map.c = get_color(ft_substr((cub3d->map.file_map[c]), 1, ft_strlen(cub3d->map.file_map[c])));
			c1++;
		}
		if (c == 6)
			mapread(cub3d, c);
		c++;
	}
}

void	print_map(t_cub3d *cub3d)
{
	int	c;

	c = 0;
	while (cub3d->map.points[c])
	{
		if (c > 9)
			printf("mapline = %d |%s|\n", c, cub3d->map.points[c]);
		else
			printf("mapline = %d  |%s|\n", c, cub3d->map.points[c]);
		c++;
	}
}

void	struck_check(t_cub3d *cub3d)
{
	printf("NO texture = %s\n", cub3d->map.t_n);
	printf("SO texture = %s\n", cub3d->map.t_s);
	printf("EA texture = %s\n", cub3d->map.t_e);
	printf("WE texture = %s\n", cub3d->map.t_w);
	printf("F = %d\n", cub3d->map.f);
	printf("C = %d\n", cub3d->map.c);
	printf("player facing = %f\n", cub3d->player.p_angle);
	printf("player location = %d, %d\n", cub3d->map.p_row, cub3d->map.p_colom);
	// print_map(cub3d);
}

void	openmap(t_cub3d *cub3d, char *argv[])
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(cub3d, 1);
	cub3d->map.file_map = ft_split(readfile(fd), '\n');
	texture_parse(cub3d);
	struck_check(cub3d);
	cub3d->player.p_x = cub3d->map.p_colom * 64 + 32;
	cub3d->player.p_y = cub3d->map.p_row * 64 + 32;
	cub3d->player.p_dx = cos(cub3d->player.p_angle) * 1;
	cub3d->player.p_dy = sin(cub3d->player.p_angle) * 1;
}

void	set_player_position(t_cub3d *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map.points[++i])
	{
		j = -1;
		while (cube->map.points[i][++j])
		{
			if (cube->map.points[i][j] != '0'
				&& cube->map.points[i][j] != ' '
				&& cube->map.points[i][j] != '1')
			{
				// cube->player.p_x = (64 * (i + (i + 1))) / 2;
				// cube->player.p_y = (64 * (j + (j + 1))) / 2;
			}
		}
	}
	cube->dir.w = false;
	cube->dir.s = false;
	cube->dir.a = false;
	cube->dir.d = false;
	cube->dir.left = false;
	cube->dir.right = false;
	cube->m = true;
}

int	main(int argc, char *argv[])
{
	t_cub3d	cube;

	if (argc != 2)
	{
		ft_putstr_fd("WRONG AMOUNT OF ARGUEMENTS", 2);
		exit(1);
	}
	openmap(&cube, argv);
	set_player_position(&cube);
	create_map(&cube);
	mlx_hook(cube.mlx_window, 17, 0, close_x, &cube);
	mlx_hook(cube.mlx_window, 2, (1L << 0), keydown, &cube);
	mlx_hook(cube.mlx_window, 3, (1L << 1), keyup, &cube);
	mlx_loop_hook(cube.mlx, move, &cube);
	mlx_loop(cube.mlx);
}

// A* search algorithm
// Flood fill Algorithm