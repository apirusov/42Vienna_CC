/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:39:48 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/15 16:49:46 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_char(t_data *data, int c)
{
    int width;

    width = data->format.width_val;
    if (width > 1)
    {
        if (data->format.left_just)
        {
            putchar_buf_n((char)c, 1, data);
            putchar_buf_n(' ', width - 1, data);
        }
        else
        {
            putchar_buf_n(' ', width - 1, data);
            putchar_buf_n((char)c, 1, data);
        }
    }
    else
        putchar_buf_n((char)c, 1, data);
}

static void set_str_padding_spaces(t_data *data, char *s)
{
	int len;
	len = ft_strlen(s);
	if (data->format.width_val > 0)
	{
		if (data->format.precision_val >= len)
			data->format.padding_spaces = data->format.width_val - len;
		else if (data->format.precision_val < 0)
			data->format.padding_spaces = data->format.width_val - data->format.precision_val;
	}
	else
		data->format.padding_spaces = data->format.width_val - len;
}

void	print_str(char *str)
{
	if (NULL == str)
		str = "(null)";
	set_str_padding_spaces(*data, *s);
	if (data->format.left_just)
	{
		if (data->format.precision_val >= 0)
			putstr_buf_n(s, data->format.precision_val, data);
		else
			putstr_buf_n(s, ft_strlen(s), data);
		putchar_buf_n(' ', data->format.padding_spaces, data);
	}
	else
	{
		putchar_buf_n(' ', data->format.padding_spaces, data);
		if (data->format.precision_val >= 0)
			putstr_buf_n(s, data->format.precision_val, data);
		else
			putstr_buf_n(s, ft_strlen(s), data);		
	}
}
