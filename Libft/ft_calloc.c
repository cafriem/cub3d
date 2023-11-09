/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:58:12 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/06 19:15:00 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if ((size != 0) && count > (SIZE_MAX / size))
		return (NULL);
	result = (void *)malloc(count * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}

// int main()
// {
// 	int	count, c;
// 	int *b;

// 	c = 0;
// 	count = 3;
// 	b = ft_calloc(count, sizeof(int));

// 	b[0] = 55;
// 	b[1] = 83;
// 	b[2] = 47;
// 	b[3] = 62;
// 	while (c != 6)
// 	{
// 		printf("%d\n", b[c]);
// 		c++;
// 	}
// 	printf("\n");
// //
// 	int	tstcount;
// 	int	c1;
// 	int *a;

// 	c1 = 0;
// 	tstcount = 3;
// 	a = calloc(tstcount, sizeof(int));

// 	a[0] = 55;
// 	a[1] = 83;
// 	a[2] = 47;
// 	a[3] = 62;
// 	while (c1 != 6)
// 	{
// 		printf("%d\n", a[c1]);
// 		c1++;
// 	}
// }
