/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:49:09 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/15 16:01:55 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		flag = *data->s;
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
	ft_bzero(&data->format, sizeof(t_format));
	data->format.precision_val = -1;
	get_flags(data);
	get_value(data, &data->format.width_val);
	if (*data->s == '.' && *(++data->s))
		get_value(data, &data->format.precision_val);
	if (!inside(SPECIFIERS, *data->s))
		return (PARSE_ERROR);
	else
	{
		data->format.specifier = *data->s;
		if (inside("diu", data->format.specifier))
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
