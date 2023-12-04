/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:26:07 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/06 18:00:44 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	c1;

	c1 = 0;
	if (n == 0)
		return (NULL);
	while ((*(unsigned char *)s) != (unsigned char)c)
	{
		s++;
		c1++;
		if (c1 >= n)
			return (NULL);
	}
	return (&(*(unsigned char *)s));
}

/*int	main(void)
{
	char s[] = "bonjourno";
	printf("%s\n", ft_memchr(s, 'n', 2));

	char tsts[] = "bonjourno";
	printf("%s\n", memchr(tsts, 'n', 2));
}*/
