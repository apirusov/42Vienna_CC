/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:06:49 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/19 13:57:12 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	itoa_base(t_data *data, unsigned int int_val)
{
	unsigned int	temp;

	if (data->fmt.base < 2 || data->fmt.base > 16)
		return ;
	if (data->fmt.is_negative && !data->fmt.is_converted)
	{
		int_val = -(int_val);
		data->fmt.is_converted = true;
		itoa_base(data, int_val);
	}
	else if (int_val < data->fmt.base)
	{
		if (data->fmt.upper_case)
			data->fmt.buf_tmp[data->fmt.num_len++] = UP_BASE[int_val];
		else
			data->fmt.buf_tmp[data->fmt.num_len++] = LOW_BASE[int_val];
	}
	else
	{
		temp = int_val / data->fmt.base;
		itoa_base(data, temp);
		temp = int_val % data->fmt.base;
		itoa_base(data, temp);
	}
}

bool	inside(const char *s, char c)
{
	if (!s)
		return (false);
	while (*s)
	{
		if (*s == c)
			return (true);
		s++;
	}
	return (false);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
		ptr[i++] = c;
	return (s);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	if (s == NULL || !*s)
		return (0);
	return (ft_strlen(s + 1) + 1);
}
