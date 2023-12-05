/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:05:05 by cafriem           #+#    #+#             */
/*   Updated: 2022/08/18 15:33:10 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(char l, int fd)
{
	write (fd, &l, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648LL)
		write (fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_print('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	if (n >= 0)
	{
		ft_print('0' + n % 10, fd);
	}
}

/*int main(void)
{
	ft_putnbr_fd(-5797);
}*/
