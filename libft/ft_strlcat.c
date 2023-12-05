/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:42:50 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/01 16:19:38 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	c1;
	size_t	c2;

	c1 = 0;
	c = ft_strlen(dst);
	c2 = ft_strlen(dst);
	if (c < dstsize)
	{
		while (src[c1] != '\0' && c + 1 != dstsize)
		{
			dst[c] = src[c1];
			c++;
			c1++;
		}
		dst[c++] = '\0';
		return (c2 + ft_strlen(src));
	}
	c1 = ft_strlen(src);
	return (c1 + dstsize);
}

// int	main(void)
// {
// 	char *dst;
// 	dst = malloc(15);
// 	memset(dst, 0, 15);
// 	memset(dst, 'r', 6);
// 	dst[11] = 'a';
// 	printf("%lu\n", ft_strlcat(dst, "lorem ipsum", 15));
// 	printf("%s\n", dst);
// //
// 	char *tstdst;
// 	tstdst = malloc(15);
// 	memset(tstdst, 0, 15);
// 	memset(tstdst, 'r', 6);
// 	tstdst[11] = 'a';
// 	printf("%lu\n", strlcat(tstdst, "lorem ipsum", 15));
// 	printf("%s\n", tstdst);
// }
