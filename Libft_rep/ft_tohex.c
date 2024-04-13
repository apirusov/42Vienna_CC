/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:48:47 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:03:15 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	to_hex_digit(int c)
{
	char	res;

	if (c > 15)
		c = 0;
	if ((c >= 0 && c < 10))
		res = '0' + c;
	else
		res = 'A' + c - 10;
	return (res);
}

char	*ft_tohex(unsigned char c)
{
	size_t		i;
	int			shift;
	static char	buff[sizeof(c) * 2];

	i = 0;
	while (i < sizeof(c) * 2)
	{
		shift = (sizeof(c) * 2 - i - 1) * 4;
		buff[i] = to_hex_digit((c & (0xf << shift)) >> shift);
		i++;
	}
	return (buff);
}
