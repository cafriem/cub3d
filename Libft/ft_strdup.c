/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:55:49 by cafriem           #+#    #+#             */
/*   Updated: 2023/08/28 22:12:18 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		c;
	int		c2;
	char	*ptr;

	c2 = 0;
	if (s1 == NULL)
		return (ft_strdup(""));
	c = ft_strlen(s1);
	ptr = (char *)malloc(c + 1);
	if (ptr == NULL)
		return (NULL);
	while (c2 != c)
	{
		ptr[c2] = s1[c2];
		c2++;
	}
	ptr[c2] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int main()
// {
// 	char *s1 = "hello";
// 	char *ans;

// 	ans = ft_strdup(s1);
// 	printf("%s\n", ans);
// //
// 	char *tsts1 = "hello";
// 	char *tstans;

// 	tstans = strdup(tsts1);
// 	printf("%s\n", tstans);
// }
