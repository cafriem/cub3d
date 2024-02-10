/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:21:03 by cafriem           #+#    #+#             */
/*   Updated: 2024/02/10 23:13:52 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_BONUS_H
# define CUBE_BONUS_H

# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <signal.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define PIE 3.14
# define COS046 0.89438856137
# define SIN046 0.4472908464
# define DOF 50
# ifdef OSX
#  include <mlx.h>
#  define ESC 53
#  define PLUS 24
#  define MINUS 27
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
#  define R 15
#  define F 3
#  define X 7
#  define Q 12
#  define E 14
#  define H 4
#  define K 40
#  define I 34
#  define J 38
#  define L 37
#  define C 8
#  define M 46
#  define SHIFT 257
# else
#  include "../mlx-linux/mlx.h"
#  define ESC 65307
#  define Q 113
#  define W 119
#  define E 101
#  define R 114
#  define A 97
#  define S 115
#  define D 100
#  define F 102
#  define Z 122
#  define X 120
#  define C 99
#  define V 118
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define SHIFT 65505
#  define M 109
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_data;

typedef struct map
{
	char			**points;
	char			**file_map;
	int				width;
	int				height;
	char			*t_n;
	char			*t_s;
	char			*t_e;
	char			*t_w;
	unsigned int	**i_n;
	unsigned int	**i_s;
	unsigned int	**i_e;
	unsigned int	**i_w;
	unsigned int	**door;
	unsigned int	***torch;
	int				tnum;
	int				torchnum;
	int				p_row;
	int				p_colom;
	int				f;
	int				c;
}		t_map;

typedef struct angles
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
	bool	shift;
}		t_dir;

typedef struct player
{
	float	p_angle;
	float	p_dy;
	float	p_dx;
	float	p_y;
	float	p_x;
}		t_player;

typedef struct cub3d
{
	int			width;
	int			height;
	void		*mlx;
	void		*mlx_window;
	t_data		img;
	t_data		hud;
	t_map		map;
	t_player	player;
	t_dir		dir;
	bool		m;
	int			fail;
}		t_cub3d;

typedef struct point
{
	float	x;
	float	y;
}		t_point;

typedef struct casting
{
	int		rays;
	int		dof;
	float	x;
	float	distv;
	float	disth;
	float	distt;
	float	r_angle;
	float	angle_diff;
	t_point	rayh;
	t_point	rayv;
	t_point	off;
	t_point	player;
	t_point	lines;
	t_point	height;
}		t_cast;

typedef struct fkifiknow
{
	int		i;
	float	s;
	float	t;
	float	y;
	float	x;
}		t_dda;

void	print_filemap(t_cub3d *cube);
void	create_map(t_cub3d *cube);

//dda help:
bool	v_condition(t_point x1, float increase_x, float increase_y, int i);
bool	v_angle(t_cast *cast);

//some map:
int		mouse(int x, int y, t_cub3d *cube);
int		file_check(char *string);

// map utils:
char	*readfile(int fd);
int		create_trgb(int t, int r, int g, int b);
int		get_color(char *line);
void	check_updown(t_cub3d *cub3d, int row, int colom);
int		check_leftright(t_cub3d *cub3d, int row, int colom);

// map valid:
void	check_valid(t_cub3d *cub3d, int row, int colom);
void	map_checker(t_cub3d *cub3d);
void	map_size(t_cub3d *cub3d);
char	*get_pl(t_cub3d *cub3d, int c, char *str);
void	mapread(t_cub3d *cub3d, int start);

// more map items:
void	draw_hud(t_cub3d *cube);
void	player_info(t_cub3d *cub3d);
void	texture_parse(t_cub3d *cub3d);
void	openmap(t_cub3d *cub3d, char *argv[]);
void	set_booleans(t_cub3d *cube);

// keypresses:
void	change_angle(t_cub3d *cube);
void	change_position(t_cub3d *cube);
int		move(t_cub3d *cube);

// drawing:
void	draw_square(int i, int j, t_cub3d *cube, int color);
void	draw_angle(t_cub3d *cube3d);
void	draw_player(t_cub3d *cube3d);
double	deg2rad(double degrees);
bool	is_wall(t_cub3d *cube, t_point ray);

// dda:
void	dda(t_point x1, t_point x2, t_cub3d *cube, int color);
void	texture_dda(t_point x1, t_point x2, t_cub3d *cube, int color);
void	wall_text_h(t_point x1, t_point x2, t_cub3d *cube, t_cast *cast);
void	wall_text_v(t_point x1, t_point x2, t_cub3d *cube, t_cast *cast);
void	wall_text_d(t_point x1, t_point x2, t_cub3d *cube, t_cast *cast);

// casting:
void	draw_floor_ceiling(t_cub3d *cube);
void	set_horizontals(t_cub3d *cube, t_cast *cast);
void	set_rayh(t_cub3d *cube, t_cast *cast);
void	set_verticals(t_cub3d *cube, t_cast *cast);
void	set_rayv(t_cub3d *cube, t_cast *cast);

// map:
int		get_hex_color(t_cub3d *cube, int x, int y);
float	dist(t_point player, t_point ray, float angle);
void	initialize_cast(t_cast *cast, t_cub3d *cube);
void	cast_n_project(t_cub3d *cube, t_cast *cast);
void	draw_rays(t_cub3d *cube);

// bonus utiLs:
void	check_door(t_cub3d *cube);
void	door_msg(t_cub3d *cube, char *str, int x, int y);
void	open_door(t_cub3d *cube);
int		keydown(int keycode, t_cub3d *cube);
int		keyup(int keycode, t_cub3d *cube);

//------------DDA.c------------//
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_point(t_cub3d *cube3d);
//------------key_press.c------------//
int		move(t_cub3d *cube);
int		key_press1(int keypress, t_cub3d *cub3d);
void	key_press2(int keypress, t_cub3d *cub3d);
void	key_press3(int keypress, t_cub3d *cub3d);
void	key_press4(int keypress, t_cub3d *cub3d);
void	key_press5(int keypress, t_cub3d *cub3d);
//------------legends.c------------//
void	legends1(t_cub3d *cub3d);
void	legends2(t_cub3d *cub3d);
//------------error.c------------//
void	error(t_cub3d *cube, int flag);
//functions:
void	create_map(t_cub3d *cube);
int		close_x(t_cub3d *cube);
int		close_esc(int keycode, t_cub3d *cube);
void	pixel_put(t_data *data, int x, int y, int color);

int		keydown(int keycode, t_cub3d *cube);
int		keyup(int keycode, t_cub3d *cube);

void	draw_map(t_cub3d *cube);

void	dda(t_point x1, t_point x2, t_cub3d *cube, int color);
void	draw_torch(t_cub3d *cube, unsigned int **map);

void	free_point(unsigned int **map);
void	free_torch(unsigned int ***torch);
void	door_or_wall(t_cub3d *cube, t_cast *cast);
void	close_free(t_cub3d *cube);
int		check_digit(char *string);


double	deg2rad(double degrees);

#endif