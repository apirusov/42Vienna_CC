/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:08:38 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/23 18:34:50 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

static char	*read_file(int fd)
{
	char	*temp;
	int		char_read;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	char_read = read(fd, temp, BUFFER_SIZE);
	if (char_read < 0)
	{
		free(temp);
		return (0);
	}
	temp[char_read] = '\0';
	return (temp);
}

static char	*make_more(int fd, char *buffer)
{
	char	*char_temp;
	char	*new_buf;
	int		new_len;

	char_temp = read_file(fd);
	if (!char_temp)
		return (NULL);
	if (!char_temp[0])
	{
		free(char_temp);
		return (buffer);
	}
	if (!buffer)
		return (char_temp);
	new_len = ft_strlen(buffer) + ft_strlen(char_temp);
	new_buf = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!new_buf)
		return (NULL);
	ft_strlcpy(new_buf, buffer, new_len + 1);
	ft_strlcat(new_buf, char_temp, new_len + 1);
	free(buffer);
	free(char_temp);
	return (new_buf);
}

static char	*make_less(char *buf, char *line)
{
	char	*new_buf;
	int		new_len;

	if (!buf || !line)
		return (NULL);
	new_len = ft_strlen(line);
	if (new_len == (int)ft_strlen(buf))
	{
		free(buf);
		return (NULL);
	}
	new_buf = ft_substr(buf, new_len, ft_strlen(buf) - new_len);
	free(buf);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		char_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4095)
		return (NULL);
	line = NULL;
	if (ft_strchr_index(buffer, '\n') == -1)
	{
		char_read = ft_strlen(buffer);
		buffer = make_more(fd, buffer);
		if (char_read == ft_strlen(buffer) && buffer)
			line = ft_substr(buffer, 0, ft_strlen(buffer));
	}
	if (!buffer)
		return (NULL);
	if (!line && ft_strchr_index(buffer, '\n') != -1)
		line = ft_substr(buffer, 0, ft_strchr_index(buffer, '\n') + 1);
	if (line)
	{
		buffer = make_less(buffer, line);
		return (line);
	}
	return (get_next_line(fd));
}
