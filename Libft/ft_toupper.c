/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:05 by cafriem           #+#    #+#             */
/*   Updated: 2022/05/30 14:49:16 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = (c - 'a') + 'A';
		return (c);
	}
	return (c);
}

/*int	main(void)
{
	char let = 'a';
	printf("%c", ft_toupper(let));
}*/
