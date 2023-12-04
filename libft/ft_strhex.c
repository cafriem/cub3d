/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:27:43 by cafriem           #+#    #+#             */
/*   Updated: 2022/12/13 16:30:56 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strhex2(char const *str, int total, int c, int add)
{
	if (ft_strchr("0123456789", str[c]) != NULL)
	{
		if (!total || str[c] == '0')
			total += (str[c] - 48);
		else
			total += ((str[c] - 48) * pow(16, add));
	}
	if (ft_strchr("abcdef", str[c]) != NULL)
	{
		if (!total && add == 0)
			total += (str[c] - 87);
		else
			total += ((str[c] - 87) * pow(16, add));
	}
}

int	ft_strhex(char const *str)
{
	int	c;
	int	add;
	int	total;

	c = ft_strlen(str) - 1;
	add = 0;
	total = 0;
	while (c != -1)
	{
		ft_strhex2(str, total, c, add);
		add++;
		c--;
	}
	return (total);
}
