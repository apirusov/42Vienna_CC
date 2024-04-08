/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:06:27 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:47:57 by apirusov         ###   ########.fr       */
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

static int	count_words(char const *s, char c)
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

static char	*word_dup(const char *s, int from, int to)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (to - from + 1));
	if (!word)
	{
		word = NULL;
		return (0);
	}
	while (from < to)
		word[i++] = s[from++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**res;
	int		counter;

	if (!s)
		return (0);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
	{
		res = NULL;
		return (0);
	}
	i = 0;
	j = 0;
	counter = -1;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] != c && counter < 0)
			counter = i;
		else if ((s[i] == c || i == ft_strlen(s) \
				|| (s[i] == '\0' && s[i - 1] != c)) && counter >= 0)
		{
			res[j++] = word_dup(s, counter, i);
			counter = -1;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}
