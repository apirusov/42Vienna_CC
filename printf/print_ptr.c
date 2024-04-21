/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:15:21 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/21 20:00:55 by apirusov         ###   ########.fr       */
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

static void	nil_my_ptr(t_data *data)
{
	int		width;
	int		precision;
	bool	left;

	width = data->fmt.width_val;
	precision = data->fmt.prec_val;
	left = data->fmt.left_just;
	partial_init(data);
	print_nil(data, width, precision, left);
}

static size_t	ft_ptrlen(size_t int_val)
{
	size_t	len;

	len = 0;
	if (int_val == 0)
		return (1);
	while (int_val)
	{
		int_val /= 16;
		len++;
	}
	return (len);
}

static void	print_adress(t_data *data, size_t int_val)
{
	if (int_val >= data->fmt.base)
	{
		print_adress(data, int_val / data->fmt.base);
		print_adress(data, int_val % data->fmt.base);
	}
	else
	{
		if (int_val < 10)
			putchar_buf_n(int_val + '0', 1, data);
		else
			putchar_buf_n(int_val - 10 + 'a', 1, data);
	}
}

void	print_pointer(t_data *data, size_t int_val)
{
	size_t	width;

	width = data->fmt.width_val - ft_ptrlen(int_val) - 2;
	if (int_val == 0)
		nil_my_ptr(data);
	else
	{
		if (data->fmt.left_just)
		{
			put_sign(data);
			partial_init(data);
			data->fmt.left_just = true;
			data->fmt.specifier = 'p';
			print_adress(data, int_val);
		}
		putchar_buf_n(' ', width, data);
		if (!data->fmt.left_just)
		{
			put_sign(data);
			partial_init(data);
			data->fmt.specifier = 'p';
			print_adress(data, int_val);
		}
	}
}
