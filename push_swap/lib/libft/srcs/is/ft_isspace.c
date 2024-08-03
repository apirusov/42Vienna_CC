/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:48:45 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/23 20:05:58 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
SYNOPSIS
	#include <ctype.h>
	int isspace(int c);
DESCRIPTION
	isspace() checks  for  white-space characters.  In the "C" and "POSIX" 
	locales, these are: space, form-feed ('\f'), newline ('\n'), carriage return
   	('\r'), horizontal tab ('\t'), and vertical tab ('\v').
RETURN VALUE
	The  values  returned  are nonzero if the character c falls into the tested
   	class, and zero if not.
*/
#include "../../includes/libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (8192);
	return (0);
}
