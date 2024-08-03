/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <apirusov@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:20:37 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 16:07:41 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
     strnstr — locate a substring in a string

LIBRARY
     Utility functions from BSD systems (libbsd, -lbsd)

SYNOPSIS
     #include <string.h>

	 char *strnstr(const char *big, const char *little, size_t len);

DESCRIPTION
     The strnstr() function locates the first occurrence of the null-terminated
     string little in the string big, where not more than len characters are
     searched.  Characters that appear after a ‘\0’ character are not searched.
     Since the strnstr() function is a FreeBSD specific API, it should only be
     used when portability is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs nowhere in
     big, NULL is returned; otherwise a pointer to the first character of the
     first occurrence of little is returned.
*/
#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (!len)
		return (0);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (big[i + j] == '\0' && little[j] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main(int argc, char **argv)
{
	if (argc != 4)
		return 0;
	printf("My function 1: %s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
//	printf("Original f: %s\n", strnstr(argv[1], argv[2], atoi(argv[3])));

	return 0;
}*/
