/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:33:57 by cafriem           #+#    #+#             */
/*   Updated: 2022/08/29 15:19:15 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int num, int power)
{
	int	c;
	int	ret;

	c = 1;
	ret = 0;
	if (num == 0 || power == 0)
		return (0);
	while (c != power)
	{
		if (c == 1)
			ret = num * num;
		if (c > 1)
			ret = ret * num;
		c++;
	}
	return (ret);
}

// 128 64 32 16 8 4 2 1
//  0   1  1  0 0 0 0 1
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_power(0, 3));
// }