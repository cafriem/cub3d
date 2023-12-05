/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_pointer_counter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:36:50 by cafriem           #+#    #+#             */
/*   Updated: 2022/09/03 16:28:32 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_double_pointer_counter1(char **dp, int line_counter)
{
	int	c;

	c = 0;
	while (dp[line_counter][c] != '\0')
		c++;
	return (c);
}

int	ft_double_pointer_counter2(char **dp)
{
	int	line_counter;

	line_counter = 0;
	while (dp[line_counter] != NULL)
		line_counter++;
	return (line_counter);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	**main;

// 	main = ft_split("  tripouille   hello you   ", ' ');
// 	printf("%s\n", main[0]);
// 	printf("%s\n", main[1]);
// 	printf("%s\n", main[2]);
// 	printf("%s\n", main[3]);
// 	printf("%d\n", ft_double_pointer_counter2(main));
// 	printf("%d\n", ft_double_pointer_counter1(main, 0));
// 	printf("%d\n", ft_double_pointer_counter1(main, 0));
// }
