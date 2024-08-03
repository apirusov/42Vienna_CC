/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:41:22 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:35:37 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
DESCRIPTION
isascii()
	checks  whether c is a 7-bit unsigned char value that fits into the
	ASCII character set.
*/
#include "../../includes/libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ch;
	//(void) ac;
	for (ch = 0; ch < 0x8d; ch++) 
	{
		if (ft_isascii(ch))
			printf("%d.  The character is %c\n", (ch), ch);
		else
			printf("Cannot be represented by an ASCII character\n");
	}
	return (0);
}*/
