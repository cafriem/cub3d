/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:13 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/02 12:28:09 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (dstsize == 0)
	{
		c = ft_strlen(src);
		return (c);
	}
	while (src[i] != '\0' && i != dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i == dstsize)
		dst[i - 1] = '\0';
	if (src[i] == '\0')
		dst[i] = '\0';
	c = ft_strlen(src);
	return (c);
}

// int	main(void)
// {
// 	char	*dst;
// 	dst = malloc(15);
// 	char src[] = "lorem ipsum dolor sit amet";
// 	memset(dst, 0, 15);
// 	memset(dst, 'r', 6);
// 	printf("%s\n", dst);
// 	printf("%lu\n", ft_strlcpy(dst, src, 0));
// 	printf("%s\n", dst);
// //
// 	char *dst1;
// 	dst1 = malloc(15);
// 	char src1[] = "lorem ipsum dolor sit amet";
// 	memset(dst1, 0, 15);
// 	memset(dst1, 'r', 6);
// 	printf("%s\n", dst1);
// 	printf("%lu\n", strlcpy(dst1, src1, 0));
// 	printf("%s\n", dst1);
// }
