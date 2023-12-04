/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:05:19 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/30 16:57:33 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	c;

	c = 0;
	while (c != len)
	{
		((char *)dst)[c] = ((char *)src)[c];
		c++;
	}
	return (dst);
}

/*int main()
{
	char dst[] = "zyxwtuv";
	char src[] = "abcde";
	printf("%s\n", ft_memcpy(dst, src, 4));

	char tstdst[] = "zyxwtuv";
	char tstsrc[] = "abcde";
	printf("%s\n", memcpy(tstdst, tstsrc, 4));
}*/
