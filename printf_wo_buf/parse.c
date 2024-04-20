/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:49:09 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/17 19:08:35 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	atoi_printf(t_data *data)
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
		*value = va_arg(data->ap, int);
		++data->s;
		return ;
	}
	*value = atoi_printf(data);
}

static void	get_flags(t_data *data)
{
	char	flag;

	while (inside(FLAGS, *data->s))
	{
		flag = *data->s;
		if ('0' == flag)
			data->flags.zero_pad = 1;
		else if ('+' == flag)
			data->flags.plus = 1;
		else if (' ' == flag)
			data->flags.space = 1;
		else if ('#' == flag)
			data->flags.hash = true;
		else if ('-' == flag)
			data->flags.left_just = true;
		++data->s;
	}
}

int	get_format(t_data *data)
{
	ft_memset(&data->fmt, '\0', sizeof(t_format));
	data->fmt.prec_val = -1;
	get_flags(data);
	get_value(data, &data->fmt.width_val);
	if (*data->s == '.' && *(++data->s))
		get_value(data, &data->fmt.prec_val);
	if (!inside(SPECIFIERS, *data->s))
		return (PARSE_ERROR);
	else
	{
		data->fmt.specifier = *data->s;
		if (inside("diu", data->fmt.specifier))
			data->fmt.base = 10;
		else if (inside("xXp", data->fmt.specifier))
		{
			data->fmt.base = 16;
			if ('X' == data->fmt.specifier)
				data->fmt.upper_case = true;
		}
		else if (*data->s == 'o')
			data->fmt.base = 8;
		else if (*data->s == 'b')
			data->fmt.base = 2;
	}
	return (OK);
}
