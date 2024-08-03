/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:13:26 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/17 13:24:59 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
       strlen - calculate the length of a string

SYNOPSIS
       #include <string.h>
       size_t strlen(const char *s);

DESCRIPTION
       The strlen() function calculates the length of the string pointed to by s,
       excluding the terminating null byte ('\0').

RETURN VALUE
       The strlen() function returns the number of bytes in the string pointed to
       by s.
*/
#include "../../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdlib.h>
int main(void)
{
	char *s = "";
	printf("%zu\n", ft_strlen(s));
	return (0);
}*/
