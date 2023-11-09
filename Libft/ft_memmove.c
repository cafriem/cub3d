/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:40:36 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/01 17:16:28 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	c;

	if (src < dst)
	{
		c = n - 1;
		while ((int) c >= 0)
		{
			((char *)dst)[c] = ((char *)src)[c];
			c--;
		}
		return (dst);
	}
	c = 0;
	while (c < n)
	{
		((char *)dst)[c] = ((char *)src)[c];
		c++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char dst[] = "hell0";
// 	char src[] = "consectetur";
// 	printf ("%s\n", ft_memmove(&str[1], str, 5));

// 	char tstdst[] = "hell0";
// 	char tstsrc[] = "1234567";
// 	printf("%s\n", memmove(tstdst, tstsrc, 5));
// }
