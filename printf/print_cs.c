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

static char	filler(t_data *data)
{
	if (data->fmt.zero_pad)
		return ('0');
	return (' ');
}

void	print_char(t_data *data, int c)
{
	int	width;

	width = data->fmt.width_val;
	if (width > 1 && c != '%')
	{
		if (data->fmt.left_just)
		{
			putchar_buf_n((char)c, 1, data);
			putchar_buf_n(filler(data), width - 1, data);
		}
		else
		{
			putchar_buf_n(filler(data), width - 1, data);
			putchar_buf_n((char)c, 1, data);
		}
	}
	else
		putchar_buf_n((char)c, 1, data);
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

static bool	oh_no_my_str_is_null(t_data *data, char *s)
{
	if (!ft_strcmp(s, "(null)") && (data->fmt.prec_val >= 0 && \
							data->fmt.prec_val < 6))
	{
		s = "";
		data->fmt.padding_spaces = data->fmt.width_val;
		if (data->fmt.zero_pad)
			putchar_buf_n('0', data->fmt.padding_spaces, data);
		else
			putchar_buf_n(' ', data->fmt.padding_spaces, data);
		return (true);
	}
	return (false);
}

void	print_str(t_data *data, char *str)
{
	if (NULL == str)
	{
		str = "(null)";
		if (oh_no_my_str_is_null(data, str))
			return ;
	}
	set_str_padding_spaces(data, str);
	if (data->fmt.left_just)
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
}
