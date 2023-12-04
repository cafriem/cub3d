/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   john.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:10:59 by jadithya          #+#    #+#             */
/*   Updated: 2023/12/04 18:06:06 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOHN_H
# define JOHN_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include "Libft/libft.h"
# include "mlx-linux/mlx.h"

// # ifdef OSX
// #  include "mlx/mlx.h"
// #  define ESC 0x35
// #  define Q 0x0C
// #  define W 0x0D
// #  define E 0x0E
// #  define R 0x0F
// #  define A 0x00
// #  define S 0x01
// #  define D 0x02
// #  define F 0x03
// #  define Z 0x06
// #  define X 0x07
// #  define C 0x08
// #  define V 0x09
// #  define UP 0x7E
// #  define DOWN 0x7D
// #  define LEFT 0x7B
// #  define RIGHT 0x7C
// # elif LINUX
# include "mlx-linux/mlx.h"
# define ESC 65307
# define Q 113
# define W 119
# define E 101
# define R 114
# define A 97
# define S 115
# define D 100
# define F 102
# define Z 122
# define X 120
# define C 99
# define V 118
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
// # endif

//structs

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}		t_data;

typedef struct map {
	char	**points;
}		t_map;

typedef struct cub3d {
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_window;
	t_data	*img;
	t_map	map;
}		t_cub3d;

//functions:
void	create_map(t_cub3d *cube);
int		close_x(t_cub3d *cube);
int		close_esc(int keycode, t_cub3d *cube);
void	pixel_put(t_data *data, int x, int y, int color);

#endif