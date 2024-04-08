/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <apirusov@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:46:55 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:32:14 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	strrchr - locate character in string
SYNOPSIS
       #include <string.h>
       char *strrchr(const char *s, int c);

DESCRIPTION
	The strrchr() function returns a pointer to the  last  occurrence  of  the
	character c in the string s.
	Here  "character"  means  "byte"; these functions do not work with wide or
	multibyte characters.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched char‐
       acter or NULL if the character is not found.  The terminating null byte is
       considered part of the string, so that if c is specified  as  '\0',  these
       functions return a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*temp;

	i = ft_strlen(s);
	temp = s;
	s = (s + i);
	while (*s != *temp && c != *s)
		s--;
	if (*s == c)
		return ((char *)s);
	else if (c == '\0')
		return ((char *)temp);
	return (0);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	if(ac != 3)
		return (1);
	else
		printf("%s\n", ft_strrchr(av[1], *av[2]));

	return (0);
}*/
