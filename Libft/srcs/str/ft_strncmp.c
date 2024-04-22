/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <apirusov@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:52:21 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/05 14:05:30 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
       strcmp, strncmp - compare two strings

SYNOPSIS
       #include <string.h>

       int strcmp(const char *s1, const char *s2);

		int strncmp(const char *s1, const char *s2, size_t n);

DESCRIPTION
       The  strcmp()  function compares the two strings s1 and s2.  The locale is
       not taken into account (for a locale-aware  comparison,  see  strcoll(3)).
       The comparison is done using unsigned characters.

       strcmp()  returns  an  integer indicating the result of the comparison, as
       follows:

       • 0, if the s1 and s2 are equal;

       • a negative value if s1 is less than s2;

       • a positive value if s1 is greater than s2.

       The strncmp() function is similar, except it compares only the  first  (at
       most) n bytes of s1 and s2.

RETURN VALUE
       The  strcmp()  and  strncmp() functions return an integer less than, equal
       to, or greater than zero if s1 (or the first n bytes  thereof)  is  found,
       respectively, to be less than, to match, or be greater than s2.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while ((s1[i] && (s1[i] == s2[i])) && --n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h> 
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc != 4)
		return 0;
	
    printf("strncmp: %d \n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	printf("strcmp: %d \n", ft_strcmp(argv[1], argv[2]));
    return (0);
}*/
