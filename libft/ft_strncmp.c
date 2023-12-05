/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:16 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/01 16:40:18 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (s1[c] && s2[c] && c != n)
	{
		if ((unsigned char)s1[c] != (unsigned char)s2[c])
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
		c++;
	}
	if (c != n)
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
	return (0);
}

// int	main(void)
// {
// 	char	s1[] = "test\200";
// 	char	s2[] = "test\0";

// 	printf("%d\n", ft_strncmp(s1, s2, 6));
// 	printf("%d\n", strncmp(s1, s2, 6));
// }
