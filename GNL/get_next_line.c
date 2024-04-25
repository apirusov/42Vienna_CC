/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:08:38 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/24 16:40:13 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

static void ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*read_file(int fd, char *buffer)
{
	char	*temp;
	int		char_read;
	static int i = 0;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	/*1. malloc fails && buffer !empty
	2. malloc fails && buffer empty
	3. malloc ok && buffer !empty
	4. malloc ok &6 buffer empty */
	if (!temp) //1, 2
	{
		if (buffer) //1
			ft_free(&buffer);
		return (0);
	}
	// 3, 4
	char_read = read(fd, temp, BUFFER_SIZE);
	if (i == 1)
		char_read = -1;
	i++;
	/*1. read = -1 && buffer !empty
	2. read = -1 && buffer empty
	3. read = 0 && buffer !empty
	4. read = 0 && buffer empty
	5. read ok && buffer !empty
	6. read ok && buffer empty*/
	if (char_read < 0) // 1, 2
	{
		ft_free(&buffer);
		ft_free(&temp); // 1, 2 if buffer is !empty i want to pass it into gnl
		return (NULL);
	}
	/* 3, 4, 5, 6
	if 3 || 4 -> idc about buffer, char_read = 0 and there is 1 byte for \0 in temp
	if 5 || 6 -> idc about buffer, char_read = n, everything's ok 	*/
	temp[char_read] = '\0';
	return (temp);
}

static char	*expand_buffer(int fd, char *buffer)
{
	char	*char_temp;
	char	*new_buf;
	int		new_len;

	char_temp = read_file(fd, buffer);
	if (!char_temp)
		return (NULL);
	if (!char_temp[0])
	{
		ft_free(&char_temp);
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
	ft_free(&buffer);
	ft_free(&char_temp);
	return (new_buf);
}

static char	*decrement_buffer(char *buf, char *line)
{
	char	*new_buf;
	int		new_len;

	if (!buf || !line)
		return (NULL);
	new_len = ft_strlen(line);
	if (new_len == (int)ft_strlen(buf))
	{
		ft_free(&buf);
		return (NULL);
	}
	new_buf = ft_substr(buf, new_len, ft_strlen(buf) - new_len);
	ft_free(&buf); // free old buffer
	return (new_buf); 
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		char_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (printf("%p\n", buffer), NULL);
	line = NULL;
	if (ft_strchr_index(buffer, '\n') == -1) // no \n in buffer
	{
		/* save buffer length */
		char_read = ft_strlen(buffer);
		/* read file and expand buffer */
		buffer = expand_buffer(fd, buffer);
		/* if buffer didn't change and buffer is not empty */
		if (buffer && char_read == ft_strlen(buffer)) 
			line = ft_substr(buffer, 0, ft_strlen(buffer));
	}
	if (!buffer)
	{
		// printf("buffer: %p\n", buffer);
		// printf("buffer: %s\n", buffer);
		//ft_free(&buffer);
		//buffer = NULL;
		// printf("buffer: %p\n", buffer);
		// printf("buffer: %s\n", buffer);
		return (printf("%p\n", buffer), NULL);
	}
	if (!line && ft_strchr_index(buffer, '\n') != -1)
		line = ft_substr(buffer, 0, ft_strchr_index(buffer, '\n') + 1);
	if (line)
	{
		buffer = decrement_buffer(buffer, line);
		return (printf("%p\n", buffer), line);
	}
	return (printf("%p\n", buffer), get_next_line(fd));
}


char testnextline(int fd)
{
	static char *buffer;
	char *line;
	int read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (isNewLineInBuffer(buffer))
		return (getLineFromBuffer(buffer));
	while (1)
	{
		read_bytes = read(fd, line, BUFFER_SIZE);
		if (read_bytes < 0)
			return (freeBuffer(buffer));
		if (read_bytes == 0)
			return (returnWholeBuffer(buffer)); // mb getLineFromBuffer(buffer) can be the same
		line[read_bytes] = '\0';
		buffer = appendBuffer(buffer, line, read_bytes);
		if (isNewLineInBuffer(buffer))
			break ;
	}
	return (getLineFromBuffer(buffer));
}