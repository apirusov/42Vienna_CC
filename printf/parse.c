/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:49:09 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/13 15:21:19 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
%[flags]="+ 0-#" [width][.precision][length]specifier

static int atoi_printf(t_data *data)
{
	int	res;

	res = 0;
	while (inside(NUMBERS, *data->s))
		res = (res * 10) + (*data->s++ - '0');
	return (res);
}


static void	get_value(t_data *data, int *value)
{
	if (*data->s == '*')
	{
		//fetching input value of a width or precision
		*value = va_arg(data->, int);
		data->s++;
		return ;
	}
	*value = ft_atoi(data);
}	

static void	get_flags(t_data *data)
{
	char	flag;

	while (inside(FLAGS, *data->s))
	{
		flag = *data.s;
		if ('0' == flag)
			data->format.zero_pad = true;
		else if (' ' == flag)
			data->format.space = true;
		else if ('+' == flag)
			data->format.plus = true;
		else if ('-' == flag)
			data->format.left_just = true;
		else if ('#' == flag)
			data->format.hash = true;
		data->s++;
	}
}

int	get_format(t_data *data)
{
	// refresh the data
	ft_bzero(&data->format, sizeof(t_format));
	//precision can be made 0, but not width
	data->format.precision_val = -1;
	// 1. we get flags [0- #+]
	get_flags(data);
	// 2. [width *]
	get_value(data, &data->format.width_val);
	// 3. [.precision_val]
	if (*data->s == '.' && *(++data->s))
		get_value(data, &data->format.precision_val);
	if (!inside(SPECIFIERS, *data->s))
		return (PARSE_ERROR);
	else
	{
		data->format.specifier = *data->s;
		// BASES_LOG
		if (inside("diu", data->format.specifier));
			data->format.base = BASE_10;
		else if (inside("xXp", data->format.specifier))
		{
			data->format.base = BASE_16;
			if ('X' == data->format.specifier)
				data->format.upper_case = true;
		}
		else if (*data->s == 'o')
			data->format.base = BASE_8;
		else if (*data->s == 'b')
			data->format.base = BASE_2;
	}
	return (OK);
}

/*int print_format(char specifier, va_list args)
{
       size_t   count;

       count = 0;
	   if (specifier == '%')
			count += write(1, "%", 1);
	   else if (specifier == 'c')
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
     else if (specifier == 'p')
            count += print_digit((long)(va_arg(args, unsigned int)), 16, "0123456789abcdef");
       else
              count += write(1, &specifier, 1);
       return (count);
}*/

