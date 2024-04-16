/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:59:27 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/16 17:45:23 by apirusov         ###   ########.fr       */
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
#include <errno.h>
#include <limits.h>
#include <locale.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include "libftprintf.h"

void	render_format(t_data *data, char specifier)
{
	onion	int_val;

	int_val.int64 = 0;
	if (specifier == '%')
		print_char(data, '%');
	else if (specifier == 'c')
		print_char(data, va_arg(data->ap, int));
	else if (specifier == 's')
		print_str(data, va_arg(data->ap, char *));
	if (inside("dioupxXu", specifier))
	{
		if (inside("di", specifier))
		{
			int_val.int64 = (long)va_arg(data->ap, int);
			data->fmt.signed_value = true;
			if (int_val.int64 < 0)
				data->fmt.is_negative = true;
		}
		else if (specifier == 'p')
			int_val.uint64 = (unsigned long)va_arg(data->ap, void *);
		else if (inside("xXuo", specifier))
			int_val.uint64 = (unsigned long)va_arg(data->ap, unsigned int);
		print_digit(data, int_val);
	}
}

static int	init_data(t_data *data, const char *format)
{
	data->chars_written = 0;
	data->s = format;
//	data->fmt.width_val = 0;
	data->fmt.space = 0;
	data->fmt.plus = 0;
	data->buf = (char *)malloc(BUF_SIZE * sizeof(char));
	if (!data->buf)
		return (MALLOC_ERROR);
	data->buf_index = 0;
	ft_memset(data->buf, '\0', BUF_SIZE * sizeof(char));
	return (OK);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	if (init_data(&data, format))
		return (MALLOC_ERROR);
	while (*data.s)
	{
		if (*data.s == '%' && *(++data.s))
		{
			if (get_format(&data))
				return (PARSE_ERROR);
			render_format(&data, (char)data.fmt.specifier);
		}
		else
		{
			write_buf(&data, *data.s);
		}
		data.s++;
	}
	flush_buf(&data);
	va_end(data.ap);
	free(data.buf);
	return (data.chars_written);
}
