/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:53:25 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:29:23 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
SYNOPSIS
    #include <ctype.h>
		int islower(int c);
DESCRIPTION
	islower() checks for a lowercase character.   
RETURN VALUE
    The  values  returned  are nonzero if the character c falls into the tested
   	class, and zero if not.
*/
#include "libft.h"

int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
