/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <apirusov@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:14:53 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/23 20:11:11 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
       memmove - copy memory area
SYNOPSIS
       #include <string.h>
       void *memmove(void *dest, const void *src, size_t n);
DESCRIPTION
       The  memmove() function copies n bytes from memory area src to memory area
       dest.  The memory areas may overlap: copying takes  place  as  though  the
       bytes in src are first copied into a temporary array that does not overlap
       src or dest, and the bytes are then copied from  the  temporary  array  to
       dest.
RETURN VALUE
       The memmove() function returns a pointer to dest.
*/
#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if ((size_t)dest - (size_t)src < n)
	{
		i = n - 1;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
	char dest[9] = "oldstring";
	char src[9] = "newstring";

    printf("\nBefore memmove(): %s\n", dest);
	ft_memmove(dest + 2, src + 2, 8*sizeof(char));
    printf("After memmove():  %s\n", dest);
	return (0);
}*/
