/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:06:27 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/10 16:54:04 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_split
PROTOTYPE
	char **ft_split(char const *s, char c);
PARAMETERS
	s: The string to be split.
	c: The delimiter character.
DESCRIPTION
	Allocates (with malloc(3)) and returns an array of strings obtained by
   	splitting ’s’ using the character ’c’ as a delimiter. The array must end
	with a NULL pointer.
RETURN VALUE
	The array of new strings resulting from the split.
	NULL if the allocation fails.
*/
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	free_res(size_t i, char **res)
{
	while (i > 0)
	{
		i--;
		free(*(res + i));
	}
	free(res);
}

static char	**ft_real_split(char **res, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(res + i) = ft_substr(s, j, word_len(&*(s + j), c));
		if (!*(res + i))
		{
			free_res(i, res);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(res + i) = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (0);
	res = ft_real_split(res, s, c, words);
	return (res);
}
