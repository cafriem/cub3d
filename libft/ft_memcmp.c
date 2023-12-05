/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:04:54 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/01 16:35:01 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;
	int		c1;
	size_t	c2;

	c = 0;
	c1 = 0;
	c2 = 0;
	while (c != n && c2 != n)
	{
		if (((unsigned char *)s1)[c] > ((unsigned char *)s2)[c])
		{
			c1 = ((unsigned char *)s1)[c] - ((unsigned char *)s2)[c];
			c2 = n;
		}
		else if (((unsigned char *)s1)[c] < ((unsigned char *)s2)[c])
		{
			c1 = ((unsigned char *)s1)[c] - ((unsigned char *)s2)[c];
			c2 = n;
		}
		c++;
	}
	return (c1);
}

// int main()
// {
// 	char s1[] = "t\200";
// 	char s2[] = "t\0";
// 	printf("%d\n", ft_memcmp(s1, s2, 2));

// 	char tsts1[] = "t\200";
// 	char tsts2[] = "t\0";
// 	printf("%d\n", memcmp(tsts1, tsts2, 2));
// }
