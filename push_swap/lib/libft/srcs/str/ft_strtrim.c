/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:09:35 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/23 20:09:31 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_strtrim
PROTOTYPE
	char *ft_strtrim(char const *s1, char const *set);
PARAMETERS
	s1: The string to be trimmed.
	set: The reference set of characters to trim.
DESCRIPTION
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters 
	specified in ’set’ removed from the beginning and the end of the string.
RETURN VALUE
	The trimmed string.
	NULL if the allocation fails.
*/
#include "../../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
/*
int main(int ac, char **av)
{
	if(ac != 3)
		return (1);
	printf("%s\n", ft_strtrim(av[1], av[2]));
//	free(ft_strtrim(av[1], av[2]));
	return (0);
}*/
