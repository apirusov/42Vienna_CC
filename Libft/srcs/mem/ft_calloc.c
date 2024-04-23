/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:23:31 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/23 20:14:31 by apirusov         ###   ########.fr       */
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

	if (size == 0 && nmemb == 0)
	{
		ptr = (void *)malloc(0);
		return (ptr);
	}
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
int main (void)
{
	printf("%p\n", ft_calloc(SIZE_MAX/2, 3));
	return (0);
}*/
