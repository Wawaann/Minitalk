/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:47:17 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/12 13:05:28 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	free_all(char **buffer, char *buf, char *tmp)
{
	if (buf)
		free(buf);
	if (tmp)
		free(tmp);
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

void	set_buffer(int fd, char **buffer)
{
	char	*buf;
	char	*tmp;
	int		byte_read;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return ;
	buf[BUFFER_SIZE] = '\0';
	tmp = NULL;
	while (ft_strchr(*buffer, '\n') == NULL)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (free_all(buffer, buf, tmp));
		if (byte_read == 0)
			return (free_all(NULL, buf, NULL));
		buf[byte_read] = '\0';
		tmp = gnl_strjoin(*buffer, buf);
		if (tmp == NULL)
			return (free_all(buffer, buf, NULL));
		*buffer = tmp;
	}
	free(buf);
}

void	reset_buffer(char **buffer)
{
	char	*end_line;
	char	*tmp;

	end_line = ft_strchr(*buffer, '\n');
	if (!end_line || ft_strlen_to(end_line + 1, '\0') == 0)
	{
		return (free_all(buffer, NULL, NULL));
	}
	tmp = ft_strdup(end_line + 1);
	free_all(buffer, NULL, NULL);
	if (tmp)
	{
		*buffer = tmp;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024] = {NULL};
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	set_buffer(fd, &buffer[fd]);
	if (buffer[fd] == NULL)
	{
		return (NULL);
	}
	line = ft_substr(buffer[fd], 0, ft_strlen_to(buffer[fd], '\n') + 1);
	if (line == NULL)
	{
		free_all(&buffer[fd], NULL, NULL);
		return (NULL);
	}
	reset_buffer(&buffer[fd]);
	return (line);
}
