/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:56:52 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:31:48 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
       strcmp, strncmp - compare two strings
SYNOPSIS
       #include <string.h>

       int strcmp(const char *s1, const char *s2);

DESCRIPTION
       The  strcmp()  function compares the two strings s1 and s2.  The locale is
       not taken into account (for a locale-aware  comparison,  see  strcoll(3)).
       The comparison is done using unsigned characters.

       strcmp()  returns  an  integer indicating the result of the comparison, as
       follows:

       • 0, if the s1 and s2 are equal;
       • a negative value if s1 is less than s2;
       • a positive value if s1 is greater than s2.

RETURN VALUE
       The  strcmp()  and  strncmp() functions return an integer less than, equal
       to, or greater than zero if s1 (or the first n bytes  thereof)  is  found,
       respectively, to be less than, to match, or be greater than s2.
*/
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
