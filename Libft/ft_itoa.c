/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:59:40 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/14 13:34:42 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revstr(char *res, int minus)
{
	char	letter;
	int		left;
	int		right;

	left = 0;
	right = (ft_strlen(res)) - 1;
	if (minus == 1)
	{
		letter = res[left];
		res[left] = '-';
		res[right] = letter;
		right--;
		left++;
	}
	while (left <= right)
	{
		letter = res[left];
		res[left] = res[right];
		res[right] = letter;
		right--;
		left++;
	}
	res[ft_strlen(res)] = '\0';
	return (res);
}

static int	ft_sizeint(int n)
{
	int	c1;
	int	minus;

	c1 = 0;
	minus = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		if (n < 0)
		{
			n = n * -1;
			minus++;
		}
		n = n / 10;
		c1++;
	}
	if (minus == 1)
		c1++;
	return (c1);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		c;
	int		c1;
	int		minus;

	minus = n < 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	c = ft_sizeint(n);
	c1 = 0;
	res = malloc(c + 1);
	if (res == NULL)
		return (NULL);
	if (minus)
		n = n * -1;
	while (c >= 0)
	{
		res[c1++] = (char)((n % 10) + 48);
		n = n / 10;
		c--;
	}
	res[c1 - 1] = '\0';
	return (ft_revstr(res, minus));
}

// int	main(void)
// {
// 	int	n;

// 	n = 12345;
// 	printf("%s", ft_itoa(n));
// }
