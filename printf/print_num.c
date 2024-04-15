/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:41:16 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/15 17:41:18 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	put_0x(t_data *data)
{
	if ((inside("xX", data->format.specifier)
                        && data->format.hash  
                        && data->format.buf_tmp[0] != '0')
                        || data->format.specifier == 'p')
    {
        if (data->format.upper_case)
            putstr_buf_n("0X", 2, data);
        else
            putstr_buf_n("0x", 2, data);
    }

}

static void	put_sign (t_data *data)
{
	if (data->format.base == BASE_16)
		put_0x(data);
	else if (data->format.signed_value)
	{
		if (data->format.is_negative)
			putchar_buf_n('-', 1, data);
		else if (!data->format.is_negative)
		{
			if (data->format.plus)
				putchar_buf_n('+', 1, data);
			else if (!data->format.plus && data->format.space)
				putchar_buf_n(' ', 1, data);
		}
	}
}

void	print_digit(t_data, onion int_values)
{
	itoa_base(data, int_values);
	set_padding_zeroes(data);
	set_padding_spaces(data);
	if (data->format.left_just)
	{
		put_sign(data);
		putchar_buf_n('0', data->format.padding_zeros, data);
		putstr_buf_n(data->format.buf_tmp; data->format.num_len, data);
		putchar_buf_n(' ', data->format.padding_spaces, data);
	}
	else
	{
		putchar_buf_n(' ', data->format.padding_spaces, data);
		put_sign(data);
		putchar_buf_n('0', data->format.padding_zeros, data);
		putstr_buf_n(data->format.buf_tmp; data->format.num_len, data);
	}
}
