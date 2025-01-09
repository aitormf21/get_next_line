/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitor <aitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:02:21 by aitor             #+#    #+#             */
/*   Updated: 2025/01/09 14:05:29 by aitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
		len = ft_strlen(storage);
	else
		len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return(line);
}

char	*ft_clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return(ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*ft_free(char **str)
{
	free(*str);
		*str = NULL;
		return (NULL);
}

char	*ft_read_lines(int fd, char *storage)
{
	int		storaged_bytes;
	char	*buffer;

	storaged_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while ((storaged_bytes > 0) && !ft_strchr(buffer, '\n'))
	{
		storaged_bytes = read(fd, buffer, BUFFER_SIZE);
		if (storaged_bytes > 0)
		{
			buffer[storaged_bytes] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (storaged_bytes == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0)
		return (NULL);
	if((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = ft_read_lines(fd, storage);
	if(!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (ft_free(&storage));
	storage = ft_clean_storage(storage);
	return(line);
}
