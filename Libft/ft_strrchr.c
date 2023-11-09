/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:01 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/06 18:02:49 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	c1;

	c1 = 0;
	while (s[c1] != '\0')
		c1++;
	while (s[c1] != (char)c)
	{
		c1--;
		if (c1 < 0)
			return (NULL);
	}
	return (&((char *)s)[c1]);
}

/*int	main(void)
{
	char	l = 's';
	char s[] = "bonjour";
	printf("%s\n", ft_strrchr(s, l));
	printf("%s\n", strrchr(s, l));
}*/
