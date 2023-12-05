/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:40:55 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/06 16:43:43 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	c;

	c = 0;
	new = malloc(ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	while (c != ft_strlen(s))
	{
		new[c] = f(c, s[c]);
		c++;
	}
	new[c] = '\0';
	return (new);
}
