/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:00:46 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/07 18:04:58 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	size_t	c1;
	char	*res;

	c = 0;
	c1 = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len == 0)
		return (ft_strdup(""));
	res = (char *)malloc((len) + 1);
	if (res == NULL)
		return (NULL);
	while (s[c] != '\0')
	{
		if (c >= start && c1 < len)
		{
			res[c1] = s[c];
			c1++;
		}
		c++;
	}
	res[c1] = '\0';
	return (res);
}

// int	main(void)
// {
// 	printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 7, 10));
// 	// printf("%s\n", ft_substr("  tripouille  42  ", 14, 2));
// }
