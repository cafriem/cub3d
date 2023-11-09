/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:56:44 by cafriem           #+#    #+#             */
/*   Updated: 2022/09/03 13:59:27 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_res(int c1, const char *str, int minus)
{
	int	c;

	c = 0;
	while (str[c1] >= '0' && str[c1] <= '9')
	{
		c = (c * 10) + (str[c1] - 48);
		c1++;
	}
	if (minus == -1)
		return (c * -1);
	return (c);
}

int	ft_atoi(const char *str)
{
	int	c;
	int	c1;
	int	minus;

	c1 = 0;
	c = 0;
	minus = 0;
	while (str[c1] == ' ' || (str[c1] >= 9 && str[c1] <= 13))
		c1++;
	while (str[c1] == '-' || str[c1] == '+')
	{
		if (str[c1] == '-')
			minus--;
		c++;
		c1++;
	}
	if (c > 1)
		return (0);
	return (ft_res(c1, str, minus));
}

/*int main()
{
	char str[] = "   -+342iniwn232";
	printf("%d\n", ft_atoi(str));
//
	char tetstr[] = "   -+342iniwn232";
	printf("%d\n", atoi(tetstr));
}*/
