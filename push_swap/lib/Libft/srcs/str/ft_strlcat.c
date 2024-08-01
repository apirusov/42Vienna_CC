/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <apirusov@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:45:10 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/09 13:37:16 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	strlcat — size-bounded string copying and concatenation

LIBRARY
     Utility functions from BSD systems (libbsd, -lbsd)

SYNOPSIS
     #include <string.h>

     size_t strlcat(char *dst, const char *src, size_t size);

DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings respec‐
     tively.  They are designed to be safer, more consistent, and less error
     prone replacements for strncpy(3) and strncat(3).  Unlike those functions,
     strlcpy() and strlcat() take the full size of the buffer (not just the
     length) and guarantee to NUL-terminate the result (as long as size is larger
     than 0 or, in the case of strlcat(), as long as there is at least one byte
     free in dst).  Note that a byte for the NUL should be included in size.
     Also note that strlcpy() and strlcat() only operate on true “C” strings.
     This means that for strlcpy() src must be NUL-terminated and for strlcat()
     both src and dst must be NUL-terminated.

	 The strlcat() function appends the NUL-terminated string src to the end of
     dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
     the result.

RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the string
     they tried to create.  For strlcpy() that means the length of src.  For
     strlcat() that means the initial length of dst plus the length of src.
     While this may seem somewhat confusing, it was done to make truncation de‐
     tection simple.
	Note, however, that if strlcat() traverses size characters without finding a
     NUL, the length of the string is considered to be size and the destination
     string will not be NUL-terminated (since there was no space for the NUL).
     This keeps strlcat() from running off the end of a string.  In practice this
     should not happen (as it means that either size is incorrect or that dst is
     not a proper “C” string).  The check exists to prevent potential security
     problems in incorrect code.
*/
#include "../../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dest && !size)
		return (0);
	i = ft_strlen(dest);
	if (size <= i)
		return (size + ft_strlen(src));
	while (src[j] && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    if(argc !=4)
	{
    	return (0);
	}
//	printf("%lu\n", strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4);
//	printf("%lu\n", strlen() + 4);
//	printf("strlcat: zu\n", strlcat("", "thx to ntoniolo for this test !", 4));
    printf("%zu \n", ft_strlcat(argv[1], argv[2], atoi(argv[3])));

    return (0);
}*/
