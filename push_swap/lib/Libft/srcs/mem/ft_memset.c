/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:45:15 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:06:41 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*NAME
memset - fill memory with a constant byte

SYNOPSIS
       #include <string.h>
       void *memset(void *s, int c, size_t n);

DESCRIPTION
       The  memset()  function fills the first n bytes of the memory area pointed
       to by s with the constant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.
*/

#include "../../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
		ptr[i++] = c;
	return (s);
}
/*
int main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";

    printf("\nBefore memset(): %s\n", str); 
    // Fill 8 characters starting from str[13] with '.' 
    ft_memset(str + 13, '.', 8*sizeof(char)); 
    printf("After memset():  %s\n", str);
	return (0);
}*/
