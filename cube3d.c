/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:29 by cafriem           #+#    #+#             */
/*   Updated: 2023/11/16 13:13:43 by cafriem          ###   ########.fr       */
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

void	ft_txthex(char *txt)
{
	char	**
}

void	texture_parse(t_data *img)
{
	int	c;

	c = 0;
	while(img->file_map[c])
	{
		if (ft_strncmp(img->file_map[c], "NO ./", 4) == 0)
			img->t_n = ft_strchr(img->file_map[c], '.');
		if (ft_strncmp(img->file_map[c], "SO ./", 4) == 0)
			img->t_s = ft_strchr(img->file_map[c], '.');
		if (ft_strncmp(img->file_map[c], "EA ./", 4) == 0)
			img->t_e = ft_strchr(img->file_map[c], '.');
		if (ft_strncmp(img->file_map[c], "WE ./", 4) == 0)
			img->t_w = ft_strchr(img->file_map[c], '.');
		if (ft_strncmp(img->file_map[c], "F ", 4) == 0)
			img->t_w = ft_strchr(img->file_map[c], '.');
		if (ft_strncmp(img->file_map[c], "C ", 4) == 0)
			img->t_w = ft_strchr(img->file_map[c], '.');
		c++;
	}
}

void	struck_check(t_data *img)
{
	printf("NO texture = %s\n", img->t_n);
	printf("SO texture = %s\n", img->t_s);
	printf("EA texture = %s\n", img->t_e);
	printf("WE texture = %s\n", img->t_w);
	printf("F = %s\n", img->f);
	printf("C = %s\n", img->c);
	
}

void	openmap(t_data *img, char *argv[])
{
	int		fd;
	int		c;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(img, 1);
	c = 0;
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