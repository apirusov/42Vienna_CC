/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:59:27 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/13 15:21:34 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
       printf - display text according to a format string
SYNOPSIS
          printf FORMAT [ARGUMENT ...]
DESCRIPTION
       printf uses the format string FORMAT to print the ARGUMENT arguments. 
	   This means that it takes format specifiers in the format string and 
	   replaces each with an argument.

       The format argument is re-used as many times as necessary to convert 
	   all of  the  given  arguments. So printf %s\n flounder catfish clownfish
	   shark will print four lines.

       Unlike echo, printf does not append a new line unless it is specified 
	   as part of the string.

       It  doesn't support any options, so there is no need for a -- separator,
	   which makes it easier to use for arbitrary input than echo. [1]

FORMAT SPECIFIERS
       Valid format specifiers are taken from the C library function printf(3):

       • %d or %i: Argument will be used as decimal integer (signed or 
	   unsigned)
       • %o: An octal unsigned integer
       • %u: An unsigned decimal integer - this means negative numbers will 
	   wrap around
       • %x or %X: An unsigned hexadecimal integer
       • %f, %g or %G: A floating-point number. %f defaults to  6  places  
	   after  the  decimal  point (which is locale-dependent - e.g. in de_DE it
	   will be a ,). %g and %G will trim trailing zeroes and switch to 
	   scientific notation (like %e) if the numbers get small or large enough.
       • %e or %E: A floating-point number in scientific (XXXeYY) notation
       • %s: A string
       • %b: As a string, interpreting backslash escapes, except that octal 
	   escapes are of the form 0 or 0ooo.
       %% signifies a literal "%".
       Conversion  can fail, e.g. "102.234" can't losslessly convert to an 
	   integer, causing printf to print an error. If you are okay with losing 
	   information, silence errors with 2>/dev/null.
	
	   A number between the % and  the  format  letter  specifies  the  width.  
	   The result will be left-padded with spaces.

BACKSLASH ESCAPES
       printf also knows a number of backslash escapes:
       • \" double quote
       • \\ backslash
       • \a alert (bell)
       • \b backspace
       • \c produce no further output
       • \e escape
       • \f form feed
       • \n new line
       • \r carriage return
       • \t horizontal tab
       • \v vertical tab
       • \ooo octal number (ooo is 1 to 3 digits)
       • \xhh hexadecimal number (hhh is 1 to 2 digits)
       • \uhhhh 16-bit Unicode character (hhhh is 4 digits)
       • \Uhhhhhhhh 32-bit Unicode character (hhhhhhhh is 8 digits)

ERRORS AND RETURN STATUS
       If the given argument doesn't work for the given format (like when you 
	   try to convert a number like 3.141592 to an integer), printf prints an 
	   error, to stderr. printf will then also  return non-zero, but will still 
	   try to print as much as it can.
       It  will  also  return  non-zero  if no argument at all was given, in 
	   which case it will print nothing.

EXAMPLE
       printf '%s\t%s\n' flounder fish

       Will print "flounder    fish" (separated with a tab character), 
	   followed by a newline  character.  This is useful for writing completions,
	   as fish expects completion scripts to output the option followed by the 
	   description, separated with a tab character.

          printf '%s: %d' "Number of bananas in my pocket" 42

       Will print "Number of bananas in my pocket: 42", without a newline.
*/
# include <errno.h>
# include <limits.h>
# include <locale.h>
# include <libexplain/malloc.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stderr.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

int	print_char(int c)
{
       return (write(1, &c, 1));
}

int	print_str(char *str)
{
	size_t	count;

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
}

int	print_format(char specifier, va_list args)
{
       size_t	count;

       count = 0;
       if (specifier == 'c')
              count += print_char(va_arg(args, int)); // (char) actually casts an int
       else if (specifier == 's')
              count += print_str(va_arg(args, char *));
       else if (specifier == 'd')
              count += print_digit((long)(va_arg(args, int)), 10, "0123456789");
	   else if (specifier == 'u')
			   count += print_digit((long)(va_arg(args, unsigned int)), 10, "0123456789");
       else if (specifier == 'o')
              count += print_digit((long)(va_arg(args, unsigned int)), 8, "01234567");
       else if (specifier == 'x')
              count += print_digit((long)(va_arg(args, unsigned int)), 16, "0123456789abcdef");
	   else if (specifier == 'X')
              count += print_digit((long)(va_arg(args, unsigned int)), 16, "0123456789ABCDEF");
/*	   else if (specifier == 'p')
			count += print_digit((long)(va_arg(args, unsigned int)), 16, "0123456789abcdef");*/
       else 
              count += write(1, &specifier, 1);
       return (count);
}

%[flags][width][.precision][length]specifier
static int	init_data(t_data *data, const char *format)
{
	data->chars_written = 0;
	data->s = format; //copy pointer of format string into data s
	data->buf = (char *)malloc(BUF_SIZE * sizeof(char));
	if (!data->buf)
		return (MALLOC_ERROR);
	data->buffer_index = 0;
	ft_bzero(data->buf, BUF_SIZE * sizeof(char)); 
	return (OK);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;
	va_list	args;
	int		count;

	va_start(data.ap, format); // we kick the data from format in a data structure
	if (init_data(&data, format)) // implicit declaration of a function
		return (ERROR);
	while (*data.s)
	{
		if (*data.s == '%' && *(data.s++) != '%')
		{
			if (get_format(&data)) // get_format is successfull if returns 0
				return (PARSE_ERROR);
			render_format(&data);
		}
		else
		{
//			data.buf[data.buf_index++] = *data.s;
			write_buf(&data, *data.s);
		}
		data.s++;
	}
	print_res(&data);
	va_end(data.ap);
	free(data.buf);
	return (data.chars_written);
}

int	main()
{
    char			*name = "Andrey";
    unsigned int	date =  28;
    int				month = 3;
    int				year = 1989;
	int				age = 35;
	float			age_f = 35.03;
	int				age_int = (int)age_f;
    int				i = -1;
	int				count;
	char			*str = NULL;
	char			*ptr = name; 
//	char null_char = '\0';

	count = printf("printf: \t%x\n", INT_MIN);
    count = ft_printf("ft_printf: \t%x\n\n", INT_MIN);
	printf ("printf: \tCharacters: %c %c \n", 'a', 65);
	ft_printf ("ft_printf: \tCharacters: %c %c \n\n", 'a', 65);
	printf ("printf: \tDecimals: %d %ld\n", 1977, 650000L);
	ft_printf ("ft_printf: \tDecimals: %d %ld\n\n", 1977, 650000L);
	printf ("printf: \tPreceding with blanks: %10d \n", 1977);
	ft_printf ("ft_printf: \tPreceding with blanks: %10d \n\n", 1977);
	printf ("printf: \tPreceding with zeros: %010d \n", 1977);
	ft_printf ("ft_printf: \tPreceding with zeros: %010d \n\n", 1977);
	printf ("printf: \tSome different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	ft_printf ("ft_printf: \tSome different radices: %d %x %o %#x %#o \n\n", 100, 100, 100, 100, 100);
	printf ("printf: \tfloats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	ft_printf ("ft_printf: \tfloats: %4.2f %+.0e %E \n\n", 3.1416, 3.1416, 3.1416);
	printf ("printf: \tWidth trick: %*d \n", 5, 10);
	ft_printf ("ft_printf: \tWidth trick: %*d \n\n", 5, 10);
	printf ("printf: \t%s \n", "A string");
	ft_printf ("ft_printf: \t%s \n\n", "A string");
	printf("printf NULL %s\n", str);
    ft_printf("ft_printf NULL %s\n\n", str);
	printf("printf ptr NULL %p\n", str);
    ft_printf("ft_printf ptr NULL %p\n\n", str);
	printf("printf ptr \t%p\n", ptr);
    ft_printf("ft_printf ptr \t%p\n\n", ptr);
	printf("printf c: \t%c\n", 99);
	ft_printf("ft_printf c: \t%c\n\n", 99);
	printf("printf  \tINT_MIN : \t%d\tINT_MAX : \t%d\n", INT_MIN, INT_MAX);
	ft_printf("ft_printf \tINT_MIN : \t%d\tINT_MAX : \t%d\n\n", INT_MIN, INT_MAX);
	printf("printf :\tage_int(35.03) = %d\n", age_int);
	ft_printf("ft_printf :\tage_int(35.03) = %d\n\n", age_int);
	printf("printf :\tHello, \t%s, you are born @ %u.%o.%d, which means you are %f years old \
or %e%% of 100. (unexpected null!) %s It also is equal to %X or %x in \"hexadecimal\"\n", name, date, month, year, age_f, age_f, str, (int)age_f, (int)age_f);
	ft_printf("ft_printf:\tHello, \t%s, you are born @ %u.%o.%d, which means you are %d \
years old or %d%% of 100. (unexpected null!) %s It also is equal to %X or %x in \"hexadecimal\"\n\n", name, date, month, year, age, age, str, (int)age_f, (int)age_f);
	printf("printf: \tHello, %s, today is %d, in hex is %x or %X, char ->%c\n", "friend", 27, 27, 27, 'R');
	ft_printf("ft_printf: \tHello, %s, today is %d, in hex is %x or %X, char ->%c\n\n", "friend", 27, 27, 27, 'R');
	printf("printf :\t");
	while (i++ < 100)
		printf("%d ", i);
	printf ("\n");
	i = -1;
	ft_printf("ft_printf :\t");
	while (i++ < 100)
		ft_printf("%d ", i);
    printf ("\n\n");

	printf("printf: \tThe chars written are %X\n", -1);
	ft_printf("ft_printf: \tThe chars written are %X\n\n", -1);
//	count = (printf(stderr, "%s\n", explain_malloc(size));
//	ft_printf("Malloc size error = %d\n", count);
}
