/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:37:27 by cafriem           #+#    #+#             */
/*   Updated: 2022/05/24 14:59:29 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i != len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	char	chicken [6];

	ft_memset(chicken, 'a', 5);
	printf("%s\n", chicken);
//
	char	test [6];

	memset(test, 'a', 5);
	printf("%s\n", test);
}*/
