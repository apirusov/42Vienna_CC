/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:39:13 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/15 16:01:28 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdbool.h>

void flush_buf(t_data *data)
{
    data->chars_written += write (STDOUT_FILENO, data->buf, data->buf_index);
    ft_bzero(data->buf, BUF_SIZE); 
    data->buf_index = 0;
}

void write_buf(t_data *data, char c)
{
    if (data->buf_index == BUF_SIZE)
    {
        flush_buf(data); 
    }
    data->buf[data->buf_index++] = c;
}

void    putchar_buf_n(char c, int precision, t_data *data)
{
    while (precision <= 0)
        return ;
    while (precision--)
        write_buf(data, c);
}

void    putstr_buf_n(char *s, int precision, t_data *data)
{
    if (precision <= 0)
        return ;
    while (precision-- && *s)
        write_buf(data, *s++);
}
