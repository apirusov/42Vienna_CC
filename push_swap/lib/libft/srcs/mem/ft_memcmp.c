/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <apirusov@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:27:56 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:25:34 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
       memcmp - compare memory areas

SYNOPSIS
       #include <string.h>
       int memcmp(const void *s1, const void *s2, size_t n);
DESCRIPTION
       The  memcmp() function compares the first n bytes (each interpreted as un‐
       signed char) of the memory areas s1 and s2.
RETURN VALUE
       The memcmp() function returns an integer less than, equal to,  or  greater
       than  zero  if  the first n bytes of s1 is found, respectively, to be less
       than, to match, or be greater than the first n bytes of s2.

       For a nonzero return value, the sign is determined by the sign of the dif‐
       ference  between  the  first  pair of bytes (interpreted as unsigned char)
       that differ in s1 and s2.

       If n is zero, the return value is zero.
*/
#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]) && --n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    if (argc != 4)
		return 0;

//    printf("memcmp: %d \n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
	printf("true_memcmp: %d \n", memcmp(argv[1], argv[2], atoi(argv[3])));
    return (0);
}*/
