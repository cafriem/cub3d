/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:12:41 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/06 14:48:05 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int l)
{
	if ((l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z'))
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	char l = 'f';
	printf("%d",ft_isalpha(l));
	printf("%d",isalpha(l));
}*/