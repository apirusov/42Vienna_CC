/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:09:59 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:24:45 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_substr
PROTOTYPE
	char *ft_substr(char const *s, unsigned int start, size_t len);
PARAMETERS
	s: The string from which to create the substring.
	start: The start index of the substring in the string ’s’.
	len: The maximum length of the substring.
DESCRIPTION
	Allocates (with malloc(3)) and returns a substring 	from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
RETURN VALUE
	The substring.
	NULL if the allocation fails.

*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || res == NULL)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
/*
int main(int ac, char **av)
{
	if(ac != 4)
		return (1);
	printf("%s\n", ft_substr(av[1], *av[2], *av[3]));
	return (0);
}*/
