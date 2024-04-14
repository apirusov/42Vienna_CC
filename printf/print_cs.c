#include "libftprintf.h"

//[-][width]

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

// %[0+ #] - NO
// [-][width][.precision] - YES 

static void set_str_padding_spaces(t_data *data, char *s)
{
	int len;
	len = ft_strlen(s);
	//check if width is OK
	if (data->format.width_val > 0)
	{
		// check if precision is OK
		if (data->format.precision_val >= len)
			data->format.padding_spaces = data->format.width_val - len;
		// write precise n from str
		//[%10.3s], "hello" -> [     hel]
		else if (data->format.precision_val < 0)
			data->format.padding_spaces = data->format.width_val - data->format.precision_val;
	}
	// no width [%10s], "hello" -> [     hello]
	else
		data->format.padding_spaces = data->format.width_val - len;
}

void	print_str(char *str)
{
	if (NULL == str)
		str = "(null)";
	// setting the spaces
	set_str_padding_spaces(*data, *s);
	// write with justification
	if (data->format.left_just)
	{
		if (data->format.precision_val >= 0)
			putstr_buf_n(s, data->format.precision_val, data);
		else
			putstr_buf_n(s, ft_strlen(s), data);

		// put padding spaces
		putchar_buf_n(' ', data->format.padding_spaces, data);
	}
	else
	{
		// put padding spaces
		putchar_buf_n(' ', data->format.padding_spaces, data);
		if (data->format.precision_val >= 0)
			putstr_buf_n(s, data->format.precision_val, data);
		else
			putstr_buf_n(s, ft_strlen(s), data);		
	}
}
/*
int	print_digit(long n, int base, char *sym)
{
	size_t	count;
	char	*symbols;

	symbols = sym;
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, symbols) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else 
	{
		count = print_digit(n / base, base, symbols);
		return (count + print_digit(n % base, base, symbols));
	}
}*/