/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:50:32 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:27:43 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
SYNOPSIS
	#include <ctype.h>
	int isupper(int c);
DESCRIPTION
	isupper() checks for an uppercase letter.
RETURN VALUE
	The  values  returned  are nonzero if the character c falls into the tested
   	class, and zero if not.
*/
#include "libft.h"

int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}
