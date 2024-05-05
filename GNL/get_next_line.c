/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:40:34 by apirusov          #+#    #+#             */
/*   Updated: 2024/05/05 13:19:22 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

static char	*ft_get_line(char **str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while ((*str)[len] && (*str)[len] != '\n')
		len++;
	if ((*str)[len] == '\n')
		len++;
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (ft_free(str), NULL);
	while (i < len)
	{
		ptr[i] = (*str)[i];
		i++;
	}
	return (ptr);
}

static char	*get_buf(char **str)
{
	char	*ptr;
	size_t	i;
	size_t	rest_str;
	size_t	j;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i])
		return (ft_free(str), NULL);
	rest_str = ft_strlen(*str) - i;
	ptr = ft_calloc(rest_str + 1, sizeof(char));
	if (!ptr)
		return (ft_free(str), NULL);
	i++;
	j = 0;
	while (j < rest_str)
		ptr[j++] = (*str)[i++];
	ft_free(str);
	return (ptr);
}

static void	*check_read_alloc(ssize_t *read_byte, int *fd,
								char **tmp_buf, char **buffer)
{
	if (*fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	(*tmp_buf) = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!(*tmp_buf))
	{
		ft_free(&(*buffer));
		return (NULL);
	}
	*read_byte = read(*fd, *tmp_buf, BUFFER_SIZE);
	if (*read_byte < 0)
	{
		ft_free(tmp_buf);
		ft_free(buffer);
		return (NULL);
	}
	return (*tmp_buf);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	char			*tmp_buf;
	ssize_t			read_byte;

	if (!check_read_alloc(&read_byte, &fd, &tmp_buf, &buffer))
		return (NULL);
	while (read_byte > 0)
	{
		tmp_buf[read_byte] = '\0';
		buffer = ft_strjoin(&buffer, tmp_buf);
		if (!buffer)
			return (ft_free(&tmp_buf), NULL);
		if (ft_strchr(buffer, '\n') == 1)
			break ;
		read_byte = read(fd, tmp_buf, BUFFER_SIZE);
	}
	ft_free(&tmp_buf);
	if (!buffer || buffer[0] == '\0')
		return (ft_free(&buffer), NULL);
	line = ft_get_line(&buffer);
	if (!line)
		return (NULL);
	buffer = get_buf(&buffer);
	return (line);
}
