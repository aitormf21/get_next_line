/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitor <aitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:02:21 by aitor             #+#    #+#             */
/*   Updated: 2025/01/07 15:12:57 by aitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	while (storaged_bytes > 0)
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0)
		return (NULL);
	if((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = ft_read_lines(fd, storage);
}
