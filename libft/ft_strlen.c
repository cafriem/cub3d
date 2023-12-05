/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:12:59 by cafriem           #+#    #+#             */
/*   Updated: 2022/08/18 15:16:14 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

// int	main (void)
// {
// 	char *str;
// 	str = "heidwadadadawdadadawdwdadwadasdawasdwasahs";
// 	printf("%zu\n",ft_strlen(str));

// 	char *tststr;
// 	tststr = "heidwadadadawdadadawdwdadwadasdawasdwasahs";
// 	printf("%zu\n",strlen(tststr));
// }