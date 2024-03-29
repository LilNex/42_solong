/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:19:56 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/16 01:26:57 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (ptr);
}

char	*cut_line(char **bak_buffer, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (*(*bak_buffer + i) != '\n' && *(*bak_buffer + i) != '\0')
		i++;
	if (*(*bak_buffer + i) == '\n')
	{
		i++;
		*line = ft_substr(*bak_buffer, 0, i);
		tmp = ft_strdup(*bak_buffer + i);
	}
	else
		*line = ft_strdup(*bak_buffer);
	free_ptr(*bak_buffer);
	return (tmp);
}

int	read_lines(int fd, char **buffer, char **bak_buffer, char **line)
{
	int		bytes;
	char	*tmp;

	bytes = 1;
	tmp = NULL;
	while (!ft_strchr(*bak_buffer, '\n') && bytes)
	{
		bytes = read(fd, *buffer, BUFFER_SIZE);
		if (bytes)
		{
			(*buffer)[bytes] = '\0';
			tmp = *bak_buffer;
			*bak_buffer = ft_strjoin(tmp, *buffer);
			free_ptr(tmp);
		}
	}
	free_ptr(*buffer);
	*bak_buffer = cut_line(bak_buffer, line);
	if (!(*line))
		free_ptr(*line);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*bak_buffer[10240];
	char		*buffer;
	char		*line[10240];

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 0)
		return (free_ptr(buffer));
	if (read(fd, buffer, 0) < 0)
		return (free_ptr(bak_buffer[fd]), bak_buffer[fd] = NULL,
			free_ptr(buffer));
	if (!bak_buffer[fd])
		bak_buffer[fd] = ft_strdup("");
	if (!read_lines(fd, &buffer, &bak_buffer[fd], &line[fd])
		&& !(*line[fd]) && buffer)
		return (free_ptr(line[fd]), free_ptr(bak_buffer[fd]), NULL);
	return (line[fd]);
}
