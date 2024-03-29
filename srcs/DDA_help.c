/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:12:15 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/12 17:27:57 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	v_condition(t_point x1, float increase_x, float increase_y, int i)
{
	if (x1.x + (increase_x * i) >= 0 && x1.x
		+ (increase_x * i) < 800 && x1.y + (increase_y * i) >= 0
		&& x1.y + (increase_y * i) < 800)
		return (true);
	return (false);
}

bool	v_angle(t_cast *cast)
{
	if (cast->r_angle > 90 && cast->r_angle < 270)
		return (true);
	return (false);
}
