/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:02:37 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/15 16:17:28 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void set_padding_zeros(t_data *data)
{
	if (data->format.precision_val >= 0)
	{
		if (data->format.precision_val > data->format.num_len)
		{
			data->format.padding_zeros = data->format.precision_val - \
										 data->format.num_len;
			return ;
		}
	}
	if (data->format.zero_pad)
	{
		if (data->format.left_just)
			return ;
		if (data->format.width_val > data->format.num_len)
			data->format.padding_zeros = data->format.width_val - \
										 data->format.num_len;
		if (data->format.specifier == 'u')
			return ;
		else if ((inside("xX", data->format.specifier) 
						&& data->format.hash
						&& data->format.buf_tmp[0] != '0')
						|| data->format.specifier == 'p')
			data->format.padding_zeros -=2;
		else if (data->format.is_negative 
						|| (!data->format.is_negative) 
						&& (data->format.plus || data->format.space))
			data->format.padding_zeros--;
	}
	if (data->format.padding_zeros < 0)
		data->format.padding_zeros = 0;
}
