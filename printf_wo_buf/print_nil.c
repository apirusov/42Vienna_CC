/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:15:21 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/19 12:23:06 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nil(t_data *data, int width, int precision, bool left)
{
	if (left && precision >= 0)
	{
		putstr_buf_n("(nil)", precision, data);
		putchar_buf_n(' ', width - precision, data);
	}
	else if (left && precision < 0)
	{
		putstr_buf_n("(nil)", 5, data);
		putchar_buf_n(' ', width - 5, data);
	}
	else if (!left && precision >= 0)
	{
		putchar_buf_n(' ', width - precision, data);
		putstr_buf_n("(nil)", precision, data);
	}
	else if (!left && precision < 0)
	{
		putchar_buf_n(' ', width - 5, data);
		putstr_buf_n("(nil)", 5, data);
	}
}

int	nil_my_ptr(t_data *data)
{
	int		width;
	int		precision;
	bool	left;
	int	chars_printed;

	chars_printed = 0;
	width = data->fmt.width_val;
	precision = data->fmt.prec_val;
	left = data->flags.left_just;
	partial_init(data);
	print_nil(data, width, precision, left);
	return (chars_printed);
}

int was_neg(t_data *data)
{
	if (data->fmt.is_negative && data->fmt.is_converted)
		return (1);
	return (0);
}
