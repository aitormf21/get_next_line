/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitor <aitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:02:21 by aitor             #+#    #+#             */
/*   Updated: 2025/01/13 11:22:50 by aitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage)
		return NULL;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char *ft_next(char *storage)
{
    int i;
    int j;
    char *line;

    i = 0;
    if (!storage)
        return (NULL);
    while (storage[i] && storage[i] != '\n')
        i++;
    if (!storage[i])
    {
        free(storage);
        return (NULL);
    }
    if (!storage[++i])
    {
        free(storage);
        return (NULL);
    }
    line = malloc(sizeof(char) * (ft_strlen(&storage[i]) + 1));
    if (!line)
    {
        free(storage);
        return (NULL);
    }
    j = 0;
    while (storage[i])
        line[j++] = storage[i++];
    line[j] = '\0';
    free(storage);
    return (line);
}

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer,buf);
	free(buffer);
	return(temp);
}

char	*ft_read_file(int fd, char *storage)
{
	int		bytes;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = 0;
		storage = ft_free(storage, buffer);
		if (!storage)
			return (NULL);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = ft_read_file(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_new_line(storage);
	storage = ft_next(storage);
	return(line);
}
