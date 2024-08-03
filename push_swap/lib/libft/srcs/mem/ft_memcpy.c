/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:12:56 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:31:32 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*NAME
memcpy - copy memory area

SYNOPSIS
       #include <string.h>
       void *memcpy(void *dest, const void *src, size_t n);

DESCRIPTION
       The  memcpy()  function copies n bytes from memory area src to memory area
       dest.  The memory areas must not overlap.  Use memmove(3)  if  the  memory
       areas do overlap.

RETURN VALUE
       The memcpy() function returns a pointer to dest.
*/

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
 
int main()
{
    char str1[] = "Geeks";
    char str2[] = "Quiz";
 
    puts("str1 before memcpy ");
    puts(str1);
 
    // Copies contents of str2 to str1
    memcpy(str1, str2, sizeof(str2));
 
    puts("\nstr1 after memcpy ");
    puts(str1);
 
    return (0);
}*/
