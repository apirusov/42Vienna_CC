/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:06:49 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/15 16:02:15 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	itoa_base(t_data *data, onion int_values)
{
	onion	temp;
	if (data->format.base < 2 || data->format.base > 16)
		return ;
	if (data->format.is_negative && !data->format.is_converted)
	{
		int_values.int64 = -(int_values.int64);
		data->format.is_converted = true;
		itoa_base(data, int_values);
	}
	else if (int_values.uint64 < data->format.base)
	{
		if (data->format.upper_case)
			data->format.buf_tmp[data->format.num_len++] = UP_BASE[int_values.uint64];
		else
			data->format.buf_tmp[data->format.num_len++] = LOW_BASE[int_values.uint64];	
	}
	else
	{
		temp.uint64 = int_values.uint64 / data->format.base;
		itoa_base(data, temp);
		temp.uint64 = int_values.uint64 % data->format.base;
		itoa_base(data, temp);
	}
}

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

