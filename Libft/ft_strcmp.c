/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 02:03:01 by smokashi          #+#    #+#             */
/*   Updated: 2023/08/30 02:03:04 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	c;

	c = 0;
	while (s1[c] && s2[c])
	{
		if ((unsigned char)s1[c] != (unsigned char)s2[c])
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
		c++;
	}
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
