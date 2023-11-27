/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:29 by cafriem           #+#    #+#             */
/*   Updated: 2023/11/27 14:37:52 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

// int	map_start(char *str)
// {
// 	int	c;

// 	c = 0;
// 	while (str[c])
// 	{
// 		if (str)
// 		c++;
// 	}
// }

int	check_updown(t_data *img, int row, int colom)
{
	int	vertical;

	vertical = row;
	while (img->map[vertical][colom] != '1') //checks up
	{
		vertical--;
		if (vertical == 0)
			return (0);
	}
	vertical = row;
	while (img->map[vertical][colom] != '1') //checks down
	{
		vertical++;
		if (vertical < img->map_height)
			return (0);
	}
	return (1);
}

// int	check_leftright(t_data *img, int row, int colom)
// {
// 	int	horizontal;

// 	horizontal = colom;
// 	while (img->map[row][horizontal] != '1') //checks left
// 	{
// 		horizontal--;
// 		if (horizontal == 0)
// 			return (0);
// 	}
// 	horizontal = colom;
// 	while (img->map[row][horizontal] != '1') //checks right
// 	{
// 		horizontal++;
// 		if (horizontal < img->map_height)
// 			return (0);
// 	}
// 	return (1);
// }

void	check_valid(t_data *img, int row, int colom)
{
	int	c;

	c = 1;
	c = check_updown(img, row, colom);
	if (c == 0)
		error(img, 2);
	// c = check_leftright(img, row, colom);
	// if (c == 0)
	// 	error(img, 2);
}

void	map_checker(t_data *img)
{
	int	row;
	int colom;

	row = 0;
	while (img->map[row])
	{
		colom = 0;
		while (img->map[row][colom])
		{
			if (img->map[row][colom] == '0')
				check_valid(img, row, colom);
			colom++;
		}
	}
}

void	map_size(t_data *img)
{
	int	c;

	c = 0;
	while (img->map[c])
		c++;
	img->map_height = c;
}

void	mapread(t_data *img, int start)
{
	int		c;
	char	*str;

	c = start;
	str = ft_strdup(img->file_map[c]);
	while (img->file_map[c + 1])
	{
		c++;
		str = ft_strjoin(str, "\n");
		str = ft_strjoin(str, img->file_map[c]);
	}
	str = ft_strtrim_free(str, "\n");
	img->map = ft_split(str, '\n');
	map_size(img);
	// map_checker(img);
}

void	texture_parse(t_data *img)
{
	int	c;
	int	c1;

	c = 0;
	c1 = 0;
	while (img->file_map[c])
	{
		if (ft_strncmp(ft_strtrim(img->file_map[c], " "), "NO", 2) == 0)
		{
			img->t_n = ft_strchr(img->file_map[c], '.');
			c1++;
		}
		if (ft_strncmp(ft_strtrim(img->file_map[c], " "), "SO", 2) == 0)
		{
			img->t_s = ft_strchr(img->file_map[c], '.');
			c1++;
		}
		if (ft_strncmp(ft_strtrim(img->file_map[c], " "), "EA", 2) == 0)
		{
			img->t_e = ft_strchr(img->file_map[c], '.');
			c1++;
		}
		if (ft_strncmp(ft_strtrim(img->file_map[c], " "), "WE", 2) == 0)
		{
			img->t_w = ft_strchr(img->file_map[c], '.');
			c1++;
		}
		if (ft_strncmp(ft_strtrim(img->file_map[c], " "), "F", 1) == 0)
		{
			img->f = get_color(ft_substr((img->file_map[c]), 1, ft_strlen(img->file_map[c])));
			c1++;
		}
		if (ft_strncmp(ft_strtrim(img->file_map[c], " "), "C", 1) == 0)
		{
			img->c = get_color(ft_substr((img->file_map[c]), 1, ft_strlen(img->file_map[c])));
			c1++;
		}
		if (c == 6)
			mapread(img, c);
		c++;
	}
}

void	print_map(t_data *img)
{
	int	c;

	c = 0;
	while (img->map[c])
	{
		if (c > 9)
			printf("mapline = %d |%s|\n", c, img->map[c]);
		else
			printf("mapline = %d  |%s|\n", c, img->map[c]);
		c++;
	}
}

void	struck_check(t_data *img)
{
	printf("NO texture = %s\n", img->t_n);
	printf("SO texture = %s\n", img->t_s);
	printf("EA texture = %s\n", img->t_e);
	printf("WE texture = %s\n", img->t_w);
	printf("F = %d\n", img->f);
	printf("C = %d\n", img->c);
	print_map(img);
}

void	openmap(t_data *img, char *argv[])
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(img, 1);
	img->file_map = ft_split(readfile(fd), '\n');
	texture_parse(img);
	struck_check(img);
}

int	main(int argc, char *argv[])
{
	t_data	img;

	if (argc < 2 || argc > 2)
	{
		ft_putstr_fd("WRONG AMOUNT OF ARGUEMENTS", 2);
		exit(1);
	}
	// img.mlx = mlx_init();
	// init(&img);
	// img.mlx_win = mlx_new_window(img.mlx, 1080, 720, argv[1]);
	// img.img = mlx_new_image(img.mlx, 1080, 720);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// 	&img.line_length, &img.endian);
	openmap(&img, argv);
	// mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	// legends1(&img);
	// mlx_hook(img.mlx_win, 2, 1L << 2, key_press1, &img);
	// mlx_loop(img.mlx);
}

// A* search algorithm
// Flood fill Algorithm