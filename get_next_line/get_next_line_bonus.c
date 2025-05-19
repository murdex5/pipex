/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:26:13 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 16:08:14 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, char *buf, char *buffer)
{
	int		read_count;
	char	*temp;

	read_count = 1;
	while (read_count != 0)
	{
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count == -1)
			return (0);
		buf[read_count] = '\0';
		if (read_count == 0)
			break ;
		if (!buffer)
			buffer = ft_strdup("");
		temp = buffer;
		buffer = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
		temp = NULL;
	}
	return (buffer);
}

static char	*clean_up(char *line)
{
	int		count;
	char	*buf;

	if (!line)
		return (NULL);
	count = 0;
	while (line[count] != '\n' && line[count])
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (NULL);
	buf = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (!buf)
	{
		line[count + 1] = '\0';
		return (NULL);
	}
	if (*buf == '\0')
	{
		free(buf);
		buf = NULL;
	}
	line[count + 1] = '\0';
	return (buf);
}

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[1024];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = get_line(fd, buf, buffer[fd]);
	buffer[fd] = clean_up(line);
	free(buf);
	return (line);
}
