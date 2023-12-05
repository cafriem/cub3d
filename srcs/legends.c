/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legends.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:00:23 by cafriem           #+#    #+#             */
/*   Updated: 2023/11/09 17:00:25 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	legends1(t_data *img)
{
	mlx_string_put(img->mlx, img->mlx_win, 10, 10, img->colour, "Controls : ");
	mlx_string_put(img->mlx, img->mlx_win, 30, 50, img->colour,
		ft_strjoin("    Height = R,F = ", ft_itoa(img->height)));
	mlx_string_put(img->mlx, img->mlx_win, 30, 30, img->colour,
		"    Moving = (arrow keys)");
	mlx_string_put(img->mlx, img->mlx_win, 30, 70, img->colour,
		ft_strjoin("X rotation = A,D = ", ft_itoa(img->x)));
	mlx_string_put(img->mlx, img->mlx_win, 30, 90, img->colour,
		ft_strjoin("Y rotation = W,S = ", ft_itoa(img->y)));
	mlx_string_put(img->mlx, img->mlx_win, 30, 110, img->colour,
		ft_strjoin("Z rotation = Q,E = ", ft_itoa(img->z)));
	mlx_string_put(img->mlx, img->mlx_win, 30, 130, img->colour,
		ft_strjoin("  max X = ", ft_itoa(img->maxx)));
	mlx_string_put(img->mlx, img->mlx_win, 30, 150, img->colour,
		ft_strjoin("  max Y = ", ft_itoa(img->maxy)));
	mlx_string_put(img->mlx, img->mlx_win, 30, 170, img->colour,
		ft_strjoin("  max Z = ", ft_itoa(img->maxz)));
	legends2(img);
}

void	legends2(t_data *img)
{
	mlx_string_put(img->mlx, img->mlx_win, 30, 190, img->colour,
		"Top View = K");
	mlx_string_put(img->mlx, img->mlx_win, 30, 210, img->colour,
		"Front View = I");
	mlx_string_put(img->mlx, img->mlx_win, 30, 230, img->colour,
		"Left View = O");
	mlx_string_put(img->mlx, img->mlx_win, 30, 250, img->colour,
		"Right View = L");
	mlx_string_put(img->mlx, img->mlx_win, 30, 270, img->colour,
		"Close Help = H");
}