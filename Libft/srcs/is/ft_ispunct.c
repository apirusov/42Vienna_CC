/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:55:17 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/23 20:06:16 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SYNOPSIS
	#include <ctype.h>
	int ispunct(int c);
DESCRIPTION
	ispunct() checks for any printable character which is not a space or an 
	alphanumeric character.
RETURN VALUE
	The  values  returned  are nonzero if the character c falls into the tested
   	class, and zero if not.
*/
#include "libft.h"

int	ft_ispunct(int c)
{
	if (ft_isprint(c) && !ft_isspace(c) && !ft_isalnum(c))
		return (4);
	return (0);
}
