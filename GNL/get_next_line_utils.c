/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:40:52 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/30 17:40:54 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t i;

	i = 0;
	if (size == 0 && nmemb == 0)
	{
		ptr = (void *)malloc(0);
		return (ptr);
	}
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb)
		ptr[i++] = '\0';
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0' && (unsigned char)c != (unsigned char)*s)
		s++;
	if ((unsigned char)c == *s)
		return (1);
	return (0);
}

char	*ft_strjoin(char **s1, char *s2)
{
	ssize_t	i;
	ssize_t	j;
	char	*res;

	if (!*s1)
	{
		*s1 = (char *)ft_calloc(1, sizeof(char));
		*s1[0] = '\0';
	}
	if (!*s1 || !s2)
		return (NULL);
	res = (char *)ft_calloc(sizeof(char), ((ft_strlen(*s1) + ft_strlen(s2)) + 1));
	if (res == NULL)
		return (ft_free(s1), NULL);
	i = -1;
	if (*s1)
		while ((*s1) && (*s1)[++i])
			res[i] = (*s1)[i];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[ft_strlen(*s1) + ft_strlen(s2)] = '\0';
	ft_free(s1);
	return (res);
}