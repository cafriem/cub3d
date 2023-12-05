/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:08:17 by cafriem           #+#    #+#             */
/*   Updated: 2023/11/09 17:08:58 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		c1;
	int		c2;
	char	*ptr;

	c = 0;
	if (!s1 || !s2)
		return (NULL);
	c1 = ft_strlen(s1);
	c2 = ft_strlen(s2);
	ptr = (char *)malloc(c1 + c2 + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[c] != '\0')
	{
		ptr[c] = s1[c];
		c++;
	}
	c2 = 0;
	while (s2[c2] != '\0')
		ptr[c++] = s2[c2++];
	ptr[c] = '\0';
	return (ptr);
}

char	*ft_strjoinfree(char *str1, char *str2, int flag)
{
	char	*str3;

	str3 = ft_strjoin(str1, str2);
	if (flag == 1)
		free(str1);
	if (flag == 2)
		free(str2);
	if (flag == 3)
	{
		free(str1);
		free(str2);
	}
	return (str3);
}

// int	main(void)
// {
// 	char s1[] = "Hello my";
// 	char s2[] = "friend";
// 	printf("%s", ft_strjoin(s1, s2));
// }
