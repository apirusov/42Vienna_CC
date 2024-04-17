/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:06:49 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/17 19:09:25 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	nil_my_ptr(t_data *data)
{
	printf("we are in nil_my_ptr\n");
	data->fmt.buf_tmp[0] = '(';
	data->fmt.buf_tmp[1] = 'n';
	data->fmt.buf_tmp[2] = 'i';
	data->fmt.buf_tmp[3] = 'l';
	data->fmt.buf_tmp[4] = ')';
	data->fmt.buf_tmp[5] = '\0';
	render_format(data, 's');
}

void	itoa_base(t_data *data, onion int_val)
{
	onion	temp;

	if (data->fmt.base < 2 || data->fmt.base > 16)
		return ;
	if (data->fmt.is_negative && !data->fmt.is_converted)
	{
		int_val.int64 = -(int_val.int64);
		data->fmt.is_converted = true;
		itoa_base(data, int_val);
	}
	else if (int_val.uint64 < data->fmt.base)
	{
		if (data->fmt.upper_case)
			data->fmt.buf_tmp[data->fmt.num_len++] = UP_BASE[int_val.uint64];
		else
			data->fmt.buf_tmp[data->fmt.num_len++] = LOW_BASE[int_val.uint64];
	}
	else
	{
		temp.uint64 = int_val.uint64 / data->fmt.base;
		itoa_base(data, temp);
		temp.uint64 = int_val.uint64 % data->fmt.base;
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
