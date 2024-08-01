/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:08:43 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/03 14:39:40 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr(int nb)
{
	int	pos;
	int	array[10];
	int	counter;

	pos = 1;
	counter = 0;
	if (nb < 0)
	{
		pos = -1;
		ft_putchar('-');
	}
	while (nb / 10 != 0)
	{
		array[counter] = nb % 10 * pos;
		nb /= 10;
		counter++;
	}
	array[counter] = nb * pos;
	while (counter >= 0)
	{
		ft_putchar(array[counter] + '0');
		counter--;
	}
}
/*
int main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}*/
