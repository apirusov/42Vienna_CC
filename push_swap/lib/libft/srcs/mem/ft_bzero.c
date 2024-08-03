/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:29:37 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:12:42 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*NAME
       bzero, explicit_bzero - zero a byte string
SYNOPSIS
       #include <strings.h>
       void bzero(void *s, size_t n);
       #include <string.h>
       void explicit_bzero(void *s, size_t n);
DESCRIPTION
       The bzero() function erases the data in the n bytes of the memory starting
       at the location pointed to by s, by writing zeros (bytes containing  '\0')
       to that area.
       The  explicit_bzero() function performs the same task as bzero().  It dif‐
       fers from bzero() in that it guarantees that compiler  optimizations  will
       not  remove the erase operation if the compiler deduces that the operation
       is "unnecessary".

 */
#include "../../includes/libft.h"

void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, '\0', n));
}
/*
#include <stdlib.h>
int main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";

    printf("\nBefore memset(): %s\n", str); 
    // Fill 8 characters starting from str[13] with '.' 
    ft_bzero(str + 13, 8*sizeof(char)); 
    printf("After memset():  %s\n", str);
	return (0);
}*/
