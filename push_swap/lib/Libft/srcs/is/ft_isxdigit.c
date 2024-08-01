/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:58:08 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/23 20:01:34 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
SYNOPSIS
	#include <ctype.h>
	int isxdigit(int c);
DESCRIPTION
	isxdigit() checks for hexadecimal digits, that is, one of
		0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F.
RETURN VALUE
	The  values  returned  are nonzero if the character c falls into the tested
   	class, and zero if not.
*/
#include "../../includes/libft.h"

int	ft_isxdigit(int c)
{
	if (ft_isdigit(c) && ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
		return (4096);
	return (0);
}
