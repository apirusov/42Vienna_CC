#include "libftprintf.h"
#include <stdbool.h>

//1. When the loop is over (str over)
//2. When the buffer is full [4096 chars]

// [RANDOM\0                    ]
//write -> flush in stdout + stocks chars in buffer
void flush_buf(t_data *data)
{
    data->chars_written += write (STDOUT_FILENO, data->buf, data->buf_index);
    //refresh after call
    ft_bzero(data->buf, BUF_SIZE); 
    data->buf_index = 0;
}

void write_buf(t_data *data, char c)
{
    if (data->buf_index == BUF_SIZE)
    {
        flush_buf(data); // refresh index and write str ind stdout
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