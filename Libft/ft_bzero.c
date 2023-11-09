/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:36:37 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/08 13:46:04 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	c;

	c = 0;
	while (c != n)
	{
		((unsigned char *)s)[c] = 0;
		c++;
	}
}

/*#include <stdio.h>

int main(void)
{
	char	s[] = "hello my friend";
	char	test[] = "hello my friend";
	
	ft_bzero(s, 5);
//
	
}*/
