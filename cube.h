/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:21:03 by cafriem           #+#    #+#             */
/*   Updated: 2023/11/22 13:29:52 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <signal.h>
# include "Libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define PIE 3.14
# define ESC 53
# define PLUS 24
# define MINUS 27
# define W 13
# define A 0
# define S 1
# define D 2
// # define LEFT 123
// # define RIGHT 124
// # define DOWN 125
// # define UP 126
// # define R 15
// # define F 3
// # define X 7
// # define Q 12
// # define E 14
// # define H 4
// # define K 40
// # define I 34
// # define J 38
// # define L 37
// # define C 8
# define COS046 0.89438856137
# define SIN046 0.4472908464

typedef struct s_data
{
	void	*mlx_win;
	char	*addr;
	void	*img;
	void	*mlx;
	char	**file_map;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	char	*t_n;
	char	*t_s;
	char	*t_e;
	char	*t_w;
	int		c;
	int		f;
	
}	t_data;

//------------DDA.c------------//
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_point(t_data img, int linecount, int row);
//------------key_press.c------------//
int		key_press1(int keypress, t_data *img);
void	key_press2(int keypress, t_data *img);
void	key_press3(int keypress, t_data *img);
void	key_press4(int keypress, t_data *img);
void	key_press5(int keypress, t_data *img);
//------------legends.c------------//
void	legends1(t_data *img);
void	legends2(t_data *img);
//------------error.c------------//
void	error(t_data *img, int flag);

#endif