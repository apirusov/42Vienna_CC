/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:00:50 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/04 18:38:51 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
       atoi, atol, atoll - convert a string to an integer

SYNOPSIS
       #include <stdlib.h>

       int atoi(const char *nptr);

DESCRIPTION
       The atoi() function converts the initial portion of the string pointed to
       by nptr to int.  The behavior is the same as

           strtol(nptr, NULL, 10);

       except that atoi() does not detect errors.

       The atol() and atoll() functions behave the same as atoi(),  except  that
       they  convert  the  initial portion of the string to their return type of
       long or long long.

RETURN VALUE
       The converted value or 0 on error.
*/
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	printf("ft_atoi: %d\n", ft_atoi(av[1]));
	printf("atoi: %d\n", atoi(av[1]));
	return (0);
}*/
