/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:23:31 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:28:52 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	calloc - allocate and free dynamic memory
SYNOPSIS
       #include <stdlib.h>
       void *calloc(size_t nmemb, size_t size);
DESCRIPTION
       The calloc() function allocates memory for an array of nmemb elements  of
       size  bytes each and returns a pointer to the allocated memory.  The mem‐
       ory is set to zero.  If nmemb or size is 0, then calloc() returns  either
       NULL,  or a unique pointer value that can later be successfully passed to
       free().  If the multiplication of nmemb and size would result in  integer
       overflow,  then calloc() returns an error.  By contrast, an integer over‐
       flow would not be detected in the following call to  malloc(),  with  the
       result that an incorrectly sized block of memory would be allocated:
           malloc(nmemb * size);

RETURN VALUE
       The malloc() and calloc() functions return a  pointer  to  the  allocated
       memory, which is suitably aligned for any built-in type.  On error, these
       functions return NULL.  NULL may also be returned by a successful call to
       malloc()  with  a  size of zero, or by a successful call to calloc() with
       nmemb or size equal to zero.
*/
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (nmemb > 2147483647 / size || nmemb > -2147483648 / size)
	{
		ft_puterror("mem failure, exiting \n");
		exit(0);
	}
	if (nmemb * size == 0)
		return (ptr);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
