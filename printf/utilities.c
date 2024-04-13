/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:06:49 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/13 15:21:16 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int nb;

    i = 0;
    sign = 1;
    nb = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        if (nb == 214748364 && str[i] == '8' && sign == -1)
            return (-2147483648);
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    return (nb * sign);
}

bool	inside(const char *s, char c)
{
	if (!s)
		return (false);
	while (*s)
	{
		if (*s == c)
			return true;
		s++;
	}
	return (false);
}

void    *ft_memset(void *s, int c, size_t n)
{
    size_t          i;
    unsigned char   *ptr;

    i = 0;
    ptr = (unsigned char *)s;
    while (i < n)
        ptr[i++] = c;
    return (s);
}

void    *ft_bzero(void *s, size_t n)
{
    return (ft_memset(s, '\0', n));
}

