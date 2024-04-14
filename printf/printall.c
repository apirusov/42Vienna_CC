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

void	print_str(char *str)
{
	if (NULL == str)
		str = "(null)";
	if (data->format.left_just)
	{
		if (data->format.precision_val >= 0)
			putstr_buf_n(s, data->format.precision_val, data);
		else
			putstr_buf_n(s, ft_strlen(s), data);
		

	}
	else
	{
		while (data->format.width_val--)
			print_char(' ');
		while (*str)
			print_char((int)*str++);
	}

	if (!str)
		return (write(1, "(null)", 6) + 6);
	count = 0;
	while (*str)
	{
		print_char((int)*str);
		count++;
		str++;
	}
	return (count);
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