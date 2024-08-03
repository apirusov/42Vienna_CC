/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:20:13 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:17:41 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
       strdup, strndup, strdupa, strndupa - duplicate a string

SYNOPSIS
       #include <string.h>

       char *strdup(const char *s);
       char *strndup(const char *s, size_t n);
       char *strdupa(const char *s);
       char *strndupa(const char *s, size_t n);

DESCRIPTION
       The strdup() function returns a pointer to a new string which is a dupli‐
       cate of the string s.  Memory for the new string is  obtained  with  mal‐
       loc(3), and can be freed with free(3).

       The  strndup()  function is similar, but copies at most n bytes.  If s is
       longer than n, only n bytes are  copied,  and  a  terminating  null  byte
       ('\0') is added.

       strdupa()  and  strndupa() are similar, but use alloca(3) to allocate the
       buffer.  They are available only when using the GNU GCC suite, and suffer
       from the same limitations described in alloca(3).

RETURN VALUE
       On  success,  the  strdup()  function returns a pointer to the duplicated
       string.  It returns NULL if insufficient memory was available, with errno
       set to indicate the cause of the error.
*/
#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		ptr = NULL;
		return (NULL);
	}
	return (ft_strcpy(ptr, s));
}
/*
#include <string.h>

int main(int ac, char **av)
{
	(void)ac;
	const char *s = av[1];
	
	printf("Original string: %s\n", s);
	printf("Original string address: %p\n", s);
	printf("Duplicate string: %s\n", ft_strdup(s));
    printf("Duplicate string address: %p\n", ft_strdup(s));
	return (0);
}*/
