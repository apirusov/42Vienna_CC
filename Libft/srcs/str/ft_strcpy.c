/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:45:56 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/04 15:57:32 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
       strcpy, strncpy - copy a string

SYNOPSIS
       #include <string.h>
       char *strcpy(char *dest, const char *src);

DESCRIPTION
       The  strcpy() function copies the string pointed to by src, including the
       terminating null byte ('\0'), to the buffer  pointed  to  by  dest.   The
       strings  may  not  overlap, and the destination string dest must be large
       enough to receive the copy.  Beware of buffer overruns!  (See BUGS.)

RETURN VALUE
       The  strcpy() and strncpy() functions return a pointer to the destination
       string dest.
*/
#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
