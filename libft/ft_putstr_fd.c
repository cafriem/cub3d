/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:59:40 by cafriem           #+#    #+#             */
/*   Updated: 2022/08/18 15:33:08 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	c;
// 	int	c1;

// 	c1 = 0;
// 	c = ft_strlen(s);
// 	while (c != c1)
// 	{
// 		write(fd, &s[c1], 1);
// 		c1++;
// 	}
// }
