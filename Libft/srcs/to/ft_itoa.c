/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:24:12 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/08 18:15:40 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_itoa	
PROTOTYPE
	char *ft_itoa(int n);
PARAMETERS
	n: the integer to convert.
DESCRIPTION
	Allocates (with malloc(3)) and returns a string representing the integer
   	received as an argument. Negative numbers must be handled.
RETURN VALUE
	The string representing the integer.
	NULL if the allocation fails.
*/
#include "libft.h"

static char	*ft_zero(char *s)
{
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t	digits;

	nb = n;
	digits = ft_numlen(nb);
	if (nb < 0)
		nb *= -1;
	res = malloc(sizeof(char) * (digits + 1));
	if (!res)
	{
		res = NULL;
		return (NULL);
	}
	if (nb == 0)
		return (ft_zero(res));
	res[digits--] = '\0';
	while (nb)
	{
		res[digits--] = nb % 10 + 48;
		nb /= 10;
	}
	if (digits == 0 && res[1] != '\0')
		res[digits] = '-';
	return (res);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", ft_itoa(ft_atoi(av[1])));
	return (0);
	//  if (digits == 0 && res[1] == '\0')
    //    res[digits] = '0';
}*/
