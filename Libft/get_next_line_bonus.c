/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:13:43 by cafriem           #+#    #+#             */
/*   Updated: 2023/11/16 10:55:06 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_open(char **old, char *new, int size, int fd)
{
	while (ft_strchr(*old, '\n') == NULL)
	{
		size = read(fd, new, BUFFER_SIZE);
		if (size < BUFFER_SIZE)
		{
			new[size] = '\0';
			*old = ft_strjoin(*old, new);
			break ;
		}
		*old = ft_strjoin(*old, new);
	}
}

static char	*ft_openfile(int fd, char *old)
{
	char	*new;
	int		size;

	size = 0;
	new = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (old == NULL)
	{
		old = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		size = read(fd, old, BUFFER_SIZE);
		if (size == -1)
		{
			free (old);
			free (new);
			return (NULL);
		}
	}
	ft_open (&old, new, size, fd);
	free (new);
	return (old);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		c;

	c = 0;
	while (buffer[c] != '\n' && buffer[c] != '\0')
		c++;
	line = (ft_calloc ((c + 2), sizeof(char)));
	c = 0;
	while (buffer[c] != '\n' && buffer[c] != '\0')
	{
		line[c] = buffer[c];
		c++;
	}
	if (buffer[c] == '\n')
		line[c] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_openfile(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_line(buffer[fd]);
	if (line[0] == '\0')
	{
		free (line);
		free (buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_substr(buffer[fd], ft_strlen(line),
			ft_strlen(buffer[fd]));
	return (line);
}

// #include <stdio.h>
// int	main()
// {
// 	char	*m;
// 	int		fd;
// 	fd = open("testing 1.txt", O_RDONLY);
// 	m = get_next_line(fd); //1
// 	printf ("%s", m);
// 	free (m);
// 	m = get_next_line(fd); //1
// 	printf ("%s", m);
// 	free (m);
// 	m = get_next_line(fd); //1
// 	printf ("%s", m);
// 	free (m);
// 	close(fd);
// 	// m = get_next_line(fd); //3
// 	// free (m);
// 	// m = get_next_line(fd); //4
// 	// free (m);
// 	// m = get_next_line(fd); //5
// 	// free (m);
// 	// m = get_next_line(fd); //6
// 	// free (m);
// 	// m = get_next_line(fd); //7
// 	// free (m);
// 	// m = get_next_line(fd); //8
// 	// free (m);
// 	// m = get_next_line(fd); //9
// 	// free (m);
// }
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀
// ⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀
// ⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀
// ⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀
// ⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀
// ⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀
// ⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
// ⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
// ⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀
// ⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀
// ⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀