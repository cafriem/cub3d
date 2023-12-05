/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legends.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:00:23 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/05 11:41:55 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	legends1(t_cub3d *cub3d)
{
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 10, 10, cub3d->colour, "Controls : ");
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 50, cub3d->colour,
		ft_strjoin("    Height = R,F = ", ft_itoa(cub3d->height)));
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 30, cub3d->colour,
		"    Moving = (arrow keys)");
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 70, cub3d->colour,
		ft_strjoin("X rotation = A,D = ", ft_itoa(cub3d->x)));
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 90, cub3d->colour,
		ft_strjoin("Y rotation = W,S = ", ft_itoa(cub3d->y)));
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 110, cub3d->colour,
		ft_strjoin("Z rotation = Q,E = ", ft_itoa(cub3d->z)));
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 130, cub3d->colour,
		ft_strjoin("  max X = ", ft_itoa(cub3d->maxx)));
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 150, cub3d->colour,
		ft_strjoin("  max Y = ", ft_itoa(cub3d->maxy)));
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 170, cub3d->colour,
		ft_strjoin("  max Z = ", ft_itoa(cub3d->maxz)));
	legends2(cub3d);
}

void	legends2(t_cub3d *cub3d)
{
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 190, cub3d->colour,
		"Top View = K");
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 210, cub3d->colour,
		"Front View = I");
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 230, cub3d->colour,
		"Left View = O");
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 250, cub3d->colour,
		"Right View = L");
	mlx_string_put(cub3d->mlx, cub3d->mlx_win, 30, 270, cub3d->colour,
		"Close Help = H");
}