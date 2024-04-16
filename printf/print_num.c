/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:41:16 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/16 17:00:44 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	set_padding_zeros(t_data *data)
{
	if (data->fmt.prec_val >= 0 && (data->fmt.prec_val > data->fmt.num_len))
	{
		data->fmt.padding_zeros = data->fmt.prec_val - data->fmt.num_len;
		return ;
	}
	if (data->fmt.zero_pad)
	{
		if (data->fmt.left_just)
			return ;
		if (data->fmt.width_val > data->fmt.num_len)
			data->fmt.padding_zeros = data->fmt.width_val - data->fmt.num_len;
		if (data->fmt.specifier == 'u')
			return ;
		else if ((inside("xX", data->fmt.specifier) && \
						data->fmt.hash && data->fmt.buf_tmp[0] != '0') || \
						data->fmt.specifier == 'p')
			data->fmt.padding_zeros -= 2;
		else if ((data->fmt.is_negative || (!data->fmt.is_negative)) && \
				(data->fmt.plus || data->fmt.space))
			data->fmt.padding_zeros--;
	}
	if (data->fmt.padding_zeros < 0)
		data->fmt.padding_zeros = 0;
}

static void	set_padding_spaces(t_data *data)
{
	data->fmt.padding_spaces = data->fmt.width_val - \
									data->fmt.padding_zeros - \
									data->fmt.num_len;
	if (inside("uxXp", data->fmt.specifier))
	{
		if ((inside("xX", data->fmt.specifier) && data->fmt.hash && \
					data->fmt.buf_tmp[0] != '0') || data->fmt.specifier == 'p')
			data->fmt.padding_spaces -= 2;
		return ;
	}
}

static void	put_0x(t_data *data)
{
	if ((inside("xX", data->fmt.specifier) && data->fmt.hash && \
			data->fmt.buf_tmp[0] != '0') || data->fmt.specifier == 'p')
	{
		if (data->fmt.upper_case)
			putstr_buf_n("0X", 2, data);
		else
			putstr_buf_n("0x", 2, data);
	}
}

static void	put_sign(t_data *data)
{
	if (data->fmt.base == BASE_16)
		put_0x(data);
	else if (data->fmt.signed_value)
	{
		if (data->fmt.is_negative)
			putchar_buf_n('-', 1, data);
		else if (!data->fmt.is_negative)
		{
			if (data->fmt.plus)
				putchar_buf_n('+', 1, data);
			else if (!data->fmt.plus && data->fmt.space)
				putchar_buf_n(' ', 1, data);
		}
	}
}

void	print_digit(t_data *data, onion int_val)
{
	itoa_base(data, int_val);
	set_padding_zeros(data);
	set_padding_spaces(data);
	if (data->fmt.left_just)
	{
		put_sign(data);
		putchar_buf_n('0', data->fmt.padding_zeros, data);
		putstr_buf_n(data->fmt.buf_tmp, data->fmt.num_len, data);
		putchar_buf_n(' ', data->fmt.padding_spaces - data->fmt.plus - \
		 	data->fmt.space - data->fmt.zero_pad, data);
	}
	else
	{
		putchar_buf_n(' ', data->fmt.padding_spaces - data->fmt.plus - \
		 	data->fmt.space - data->fmt.zero_pad, data);
		put_sign(data);
		putchar_buf_n('0', data->fmt.padding_zeros, data);
		putstr_buf_n(data->fmt.buf_tmp, data->fmt.num_len, data);
	}
}
