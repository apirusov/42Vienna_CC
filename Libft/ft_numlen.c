/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:16:17 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:59:40 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_numlen
PROTOTYPE
	size_t ft_numlen(int n)
PARAMETERS
	n - the number, where the number of digits (including sign) must be found
DESCRIPTION
	Calculates the number of digits in the number, INCLUDING SIGN
RETURN VALUE
	number of signs
*/
#include "libft.h"

size_t	ft_numlen(int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		digits++;
	}
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
