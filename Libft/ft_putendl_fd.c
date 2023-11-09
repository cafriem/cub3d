/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:27:42 by cafriem           #+#    #+#             */
/*   Updated: 2022/08/18 15:33:13 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	new;
	int		c;
	int		c1;

	c1 = 0;
	c = ft_strlen(s);
	new = '\n';
	while (c != c1)
	{
		write(fd, &s[c1], 1);
		c1++;
	}
	write(fd, &new, 1);
}
