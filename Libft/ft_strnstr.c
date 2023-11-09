/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:33:30 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/06 18:20:44 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	size_t	c1;

	c = 0;
	c1 = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (c < len && c < ft_strlen(haystack))
	{
		while (haystack[c] == needle[c1] && c < len && c < ft_strlen(haystack))
		{
			c1++;
			c++;
			if (needle[c1] == '\0')
			{
				c = c - c1;
				return (&((char *)haystack)[c]);
			}
		}
		c = c - c1;
		c1 = 0;
		c++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	needle[] = "aabc";
// 	char	haystack[] = "aaabcabcd";
// 	printf("%s\n",ft_strnstr(haystack, needle, 12));
// 	printf("%s\n",strnstr(haystack, needle, 12));
// }
