/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:11:15 by jadithya          #+#    #+#             */
/*   Updated: 2024/01/31 18:48:37 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	change_angle(t_cub3d *cube)
{
	if (cube->dir.left)
		cube->player.p_angle += 1;
	if (cube->dir.right)
		cube->player.p_angle -= 1;
	if (cube->player.p_angle < 0)
		cube->player.p_angle = 360;
	else if (cube->player.p_angle >= 360)
		cube->player.p_angle = 0;
}

void	change_position(t_cub3d *cube)
{
	if (!cube->dir.shift)
	{
		cube->player.p_dx = -cos(deg2rad(cube->player.p_angle)) * 1;
		cube->player.p_dy = sin(deg2rad(cube->player.p_angle)) * 1;
	}
	else
	{
		cube->player.p_dx = -cos(deg2rad(cube->player.p_angle)) * 2;
		cube->player.p_dy = sin(deg2rad(cube->player.p_angle)) * 2;
	}
}

bool	condition(t_cub3d *cube)
{
	int	x;
	int	y;

	x = cube->player.p_y;
	y = cube->player.p_x;
	if (cube->map.points[x / 64][y / 64] == '1' || cube->map.points[x / 64][y / 64] == '2')
		return (true);
	if (cube->map.points[(x - 15) / 64][(y - 15) / 64] == '1' || cube->map.points[(x - 15) / 64][(y - 15) / 64] == '2')
		return (true);
	if (cube->map.points[(x) / 64][(y - 15) / 64] == '1' || cube->map.points[(x) / 64][(y - 15) / 64] == '2')
		return (true);
	if (cube->map.points[(x - 15) / 64][(y) / 64] == '1' || cube->map.points[(x - 15) / 64][(y) / 64] == '2')
		return (true);
	if (cube->map.points[(x + 15) / 64][(y + 15) / 64] == '1' || cube->map.points[(x + 15) / 64][(y + 15) / 64] == '2')
		return (true);
	if (cube->map.points[(x) / 64][(y + 15) / 64] == '1' || cube->map.points[(x) / 64][(y + 15) / 64] == '2')
		return (true);
	if (cube->map.points[(x + 15) / 64][(y) / 64] == '1' || cube->map.points[(x + 15) / 64][(y) / 64] == '2')
		return (true);
	if (cube->map.points[(x - 15) / 64][(y + 15) / 64] == '1' || cube->map.points[(x - 15) / 64][(y + 15) / 64] == '2')
		return (true);
	if (cube->map.points[(x + 15) / 64][(y - 15) / 64] == '1' || cube->map.points[(x + 15) / 64][(y - 15) / 64] == '2')
		return (true);
	return (false);
}

void	check_boundaries(t_cub3d *cube)
{
	if (cube->dir.a)
	{
		cube->player.p_x += cube->player.p_dy;
		if (condition(cube))
			cube->player.p_x -= cube->player.p_dy;
		cube->player.p_y -= cube->player.p_dx;
		if (condition(cube))
			cube->player.p_y += cube->player.p_dx;
	}
	if (cube->dir.d)
	{
		cube->player.p_x -= cube->player.p_dy;
		if (condition(cube))
			cube->player.p_x += cube->player.p_dy;
		cube->player.p_y += cube->player.p_dx;
		if (condition(cube))
			cube->player.p_y -= cube->player.p_dx;
	}
}

int	move(t_cub3d *cube)
{
	change_angle(cube);
	change_position(cube);
	if (cube->dir.w)
	{
		cube->player.p_x += cube->player.p_dx;
		if (condition(cube))
			cube->player.p_x -= cube->player.p_dx;
		cube->player.p_y += cube->player.p_dy;
		if (condition(cube))
			cube->player.p_y -= cube->player.p_dy;
	}
	if (cube->dir.s)
	{
		cube->player.p_x -= cube->player.p_dx;
		if (condition(cube))
			cube->player.p_x += cube->player.p_dx;
		cube->player.p_y -= cube->player.p_dy;
		if (condition(cube))
			cube->player.p_y += cube->player.p_dy;
	}
	check_boundaries(cube);
	draw_map(cube);
	return (0);
}
