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
//# include <libexplain/malloc.h>
# include <stdarg.h>
# include <stdbool.h>
//# include <stderr.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

void	render_format(t_data *data)
{
	char specifier;
	
	specifier = data->format.specifier;
	if (specifier == '%')
		print_char(data, '%');
	else if (specifier == 'c')
		print_char(data, va_arg(data->ap, int));
	else if (specifier == 's')
		print_str(data, va_arg(data->ap, char *));


	count = 0;
	if (data->format.specifier == '%')
		count += print_char(data, '%');
	else if (data->format.specifier == 'c')
		count += print_char(va_arg(data->ap, int));
	else if (data->format.specifier == 's')
		count += print_str(va_arg(data->ap, char *));
	else if (data->format.specifier == 'd')
		count += print_digit((long)(va_arg(data->ap, int)), 10, "0123456789");
	else if (data->format.specifier == 'u')
		count += print_digit((long)(va_arg(data->ap, unsigned int)), 10, "0123456789");
	else if (data->format.specifier == 'o')
		count += print_digit((long)(va_arg(data->ap, unsigned int)), 8, "01234567");
	else if (data->format.specifier == 'x')
		count += print_digit((long)(va_arg(data->ap, unsigned int)), 16, "0123456789abcdef");
	else if (data->format.specifier == 'X')
		count += print_digit((long)(va_arg(data->ap, unsigned int)), 16, "0123456789ABCDEF");
	else
		count += write(1, &data->format.specifier, 1);
	data->chars_written += count;
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


