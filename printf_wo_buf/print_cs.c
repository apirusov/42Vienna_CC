/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:39:48 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/19 12:25:30 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_char(t_data *data, int c)
{
	int	chars_printed;
	int	width;

	width = data->fmt.width_val;
	if (width > 1 && c != '%')
	{
		chars_printed = 0;
		if (data->flags.left_just)
			chars_printed += ft_print_char((char)c);
		while (width-- > 0)
			chars_printed += ft_print_char(filler(data));
		if (!data->flags.left_just)
			chars_printed += ft_print_char((char)c);
	}
	return (chars_printed);
}

static void	set_str_padding_spaces(t_data *data, char *s)
{
	int	len;

	len = ft_strlen(s);
	if (data->fmt.width_val > 0)
	{
		if (data->fmt.prec_val >= 0)
		{
			if (data->fmt.prec_val > len)
				data->fmt.padding_spaces = data->fmt.width_val - len;
			else if (data->fmt.prec_val < len)
				data->fmt.padding_spaces = data->fmt.width_val - \
					data->fmt.prec_val;
		}
		else
			data->fmt.padding_spaces = data->fmt.width_val - len;
	}
	else
		data->fmt.padding_spaces = data->fmt.width_val - len;
}

int	oh_no_my_str_is_null(t_data *data, char *s)
{
	int	chars_printed;

	chars_printed = 0;
	if (!ft_strcmp(s, "(null)") && (data->fmt.prec_val >= 0 && \
							data->fmt.prec_val < 6))
	{
		s = "";
		data->fmt.padding_spaces = data->fmt.width_val;
		if (data->flags.zero_pad)
			putchar_buf_n('0', data->fmt.padding_spaces, data);
		else
			putchar_buf_n(' ', data->fmt.padding_spaces, data);
		return (chars_printed);
	}
	return (0);
}

int	print_str(t_data *data, char *str)
{
	int	chars_printed;

	chars_printed = 0;
	if (NULL == str)
	{
		str = "(null)";
		if (oh_no_my_str_is_null(data, str))
			return (oh_no_my_str_is_null(data, str));
	}
	set_str_padding_spaces(data, str);
	if (data->flags.left_just)
	{
		if (data->fmt.prec_val >= 0)
			putstr_buf_n(str, data->fmt.prec_val, data);
		else
			putstr_buf_n(str, ft_strlen(str), data);
		putchar_buf_n(filler(data), data->fmt.padding_spaces, data);
	}
	else
	{
		putchar_buf_n(filler(data), data->fmt.padding_spaces, data);
		if (data->fmt.prec_val >= 0)
			putstr_buf_n(str, data->fmt.prec_val, data);
		else
			putstr_buf_n(str, ft_strlen(str), data);
	}
	return (chars_printed);
}
