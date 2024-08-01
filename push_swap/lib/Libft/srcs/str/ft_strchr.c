/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <apirusov@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:18:30 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 15:27:39 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
       strchr - locate character in string
SYNOPSIS
       #include <string.h>
       char *strchr(const char *s, int c);
DESCRIPTION
       The  strchr()  function  returns  a pointer to the first occurrence of the
       character c in the string s.
       Here  "character"  means  "byte"; these functions do not work with wide or
       multibyte characters.
RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched char‐
       acter or NULL if the character is not found.  The terminating null byte is
       considered part of the string, so that if c is specified  as  '\0',  these
       functions return a pointer to the terminator.

*/
#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (unsigned char)c != (unsigned char)*s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	if(ac != 3)
		return (1);
	else
		printf("%s\n", ft_strchr(av[1], *av[2]));
	
	return (0);
}*/
