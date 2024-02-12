/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:33:54 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/12 17:35:06 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	file_check(char *string)
{
	char	*str;

	str = ft_strchr(string, '.');
	if (str && ft_strcmp(str, ".cub") == 0)
		return (1);
	else
	{
		printf("Error: file invalid\n");
		exit(1);
	}
	return (0);
}
