#include "ft_printf.h"

char	filler(t_data *data)
{
	if (data->flags.zero_pad)
		return ('0');
	return (' ');
}

int ft_pad_width(t_data *data, int len)
{
    size_t chars_printed;

    chars_printed = 0;
    while (data->fmt.width_val - len > 0)
    {
        chars_printed += ft_print_char(filler(data));
        data->fmt.width_val--;
    }
    return (chars_printed);
}