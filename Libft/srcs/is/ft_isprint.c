/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:56:18 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 16:34:21 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
DESCRIPTION
isprint()
	checks for any printable character including space.
*/
#include "libft.h"

int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
		return (16384);
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int c;
//	(void) ac;
	for (c = 1; c <= 127; c++)
		if(ft_isprint(c))
			printf("%c ", c);
//	printf("%d\n", ft_isprint(*av[1]));
	return (0);
}*/
