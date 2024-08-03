/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <apirusov@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:46:55 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 14:45:38 by apirusov         ###   ########.fr       */
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

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	temp += ft_strlen(s);
	while (temp >= s)
	{
		if (*temp == (char)c)
			return (temp);
		temp--;
	}
	return (NULL);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("strrchr(\"\", 0): %s\n", strrchr("", 0));
	printf("ft_strrchr(\"\", 0): %s\n", ft_strrchr("", 0));
	printf("strrchr(\"s\", 0): %s\n", strrchr("s", 0));
    printf("ft_strrchr(\"s\", 0): %s\n", ft_strrchr("s", 0));
	printf("strrchr(\"hello\", 'l'): %s\n", strrchr("hello", 'l'));
    printf("ft_strrchr(\"hello\", 'l'): %s\n", ft_strrchr("hello", 'l'));
	printf("strrchr(\"hello\", -1): %s\n", strrchr("hello", -1));
    printf("ft_strrchr(\"hello\", -1): %s\n", ft_strrchr("hello", -1));
	printf("strrchr(\"hello\", '\\0'): %s\n", strrchr("hello", '\0'));
    printf("ft_strrchr(\"hello\", '\\0'): %s\n", ft_strrchr("hello", '\0'));
	printf("strrchr(\"hello\", 'a'): %s\n", strrchr("hello", 'a'));
    printf("ft_strrchr(\"hello\", 'a'): %s\n", ft_strrchr("hello", 'a'));
//	printf("strrchr: %s\n", strrchr());
//   printf("ft_strrchr: %s\n", ft_strrchr());
	return (0);
}*/
