/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:55:05 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 15:22:21 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
DESCRIPTION
putchar(c) is equivalent to putc(c, stdout).
*/
#include "libft.h"

void	ft_putchar(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc < 128)
		write(1, &uc, 1);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	wchar_t c;
	
	c = L'ü';
	ft_putchar(c);
	ft_putchar(*av[1]);
	return (0);
}*/
