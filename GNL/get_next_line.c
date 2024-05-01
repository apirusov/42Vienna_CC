/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:40:34 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/30 17:40:39 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

static char	*ft_getline(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*expand_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		ft_free(&buffer);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	ft_free(&buffer);
	return (res);
}

static char	*read_till_new(int fd, char *buffer)
{
	char	*tmp_buf;
	int		read_bytes;

	tmp_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, tmp_buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			ft_free(&tmp_buf);
			return (NULL);
		}
		tmp_buf[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp_buf);
	}
	ft_free(&tmp_buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_till_new(fd, buffer);
	if (!buffer)
	{	
		ft_free(&buffer);
		return (NULL);
	}
	line = ft_getline(buffer);
	buffer = expand_buffer(buffer);
	return (line);
}