/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:58:42 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/10 13:15:37 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

//size_t	ft_strlen(const char *s)
//{
//	size_t	i;

//	i = 0;
//	if (!s)
//		return (0);
//	while (s[i] != '\0')
//		i++;
//	return (i);
//}

//static void	*ft_calloc(size_t num, size_t size)
//{
//	char	*ns;
//	size_t	i;

//	if (size != 0 && num > (SSIZE_MAX / size))
//		return (NULL);
//	ns = (char *) malloc (num * size);
//	if (!ns)
//		return (NULL);
//	i = 0;
//	while (i < (num * size))
//	{
//		ns[i] = 0;
//		i++;
//	}
//	return (ns);
//}

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	if (!s1)
		s1 = (char *) ft_calloc (1, 1);
	j = (ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (j == 0)
		return (NULL);
	newstr = (char *) ft_calloc (j + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	i = -1;
	while (s1[++i])
		newstr[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	free (s1);
	return (newstr);
}

int	ft_hasnextline(char *check)
{
	int	i;

	i = 0;
	if (!check)
		return (0);
	while (check[i] != '\0')
	{
		if (check[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_splithold(char *hold)
{
	int		i;
	char	*newstr;

	newstr = (char *) ft_calloc (ft_strlen(hold) + 1, sizeof(char));
	i = 0;
	while (hold[i] != '\n' && hold[i] != 0)
	{
		newstr[i] = hold[i];
		i++;
	}
	if (hold[i] == '\n')
		newstr[i++] = '\n';
	newstr[i] = '\0';
	i = ft_strlen(newstr);
	while (hold[i] != '\0')
	{
		hold[i - ft_strlen(newstr)] = hold[i];
		i++;
	}
	hold[i - ft_strlen(newstr)] = '\0';
	return (newstr);
}
