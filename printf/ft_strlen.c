/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:13:26 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:37:23 by apirusov         ###   ########.fr       */
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
#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	if (s == NULL || !*s)
		return (0);
	return (ft_strlen(s + 1) + 1);
}
/*
#include <stdlib.h>
int main(int ac, char **av)
{
	(void) ac;
	printf("%zu\n", ft_strlen(av[1]));
	return (0);
}*/
