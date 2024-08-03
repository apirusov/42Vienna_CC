/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:31:12 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:01:38 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*NAME
       toupper, tolower, toupper_l, tolower_l - convert uppercase or lowercase

SYNOPSIS
       #include <ctype.h>

       int toupper(int c);
       int tolower(int c);
DESCRIPTION
       These functions convert lowercase letters to uppercase, and vice versa.

       If c is a lowercase letter, toupper() returns its uppercase equivalent, if
       an uppercase representation exists in the current locale.   Otherwise,  it
       returns  c.  The toupper_l() function performs the same task, but uses the
       locale referred to by the locale handle locale.

       If c is an uppercase letter, tolower() returns its  lowercase  equivalent,
       if a lowercase representation exists in the current locale.  Otherwise, it
       returns c.  The tolower_l() function performs the same task, but uses  the
       locale referred to by the locale handle locale.

       If  c  is  neither  an  unsigned char value nor EOF, the behavior of these
       functions is undefined.

       The behavior of toupper_l() and tolower_l() is undefined if locale is  the
       special  locale  object  LC_GLOBAL_LOCALE  (see  duplocale(3)) or is not a
       valid locale object handle.

RETURN VALUE
       The value returned is that of the converted letter, or c if the conversion
       was not possible.
*/
#include "../../includes/libft.h"

int	ft_toupper(int a)
{
	if (a >= 'a' && a <= 'z')
		a = a - 32;
	return (a);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	printf("%c\n", ft_toupper(*av[1]));
	return (0);
}*/
