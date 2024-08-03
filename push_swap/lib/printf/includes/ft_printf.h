/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:39:58 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/21 19:57:03 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/includes/libft.h"
# include <limits.h>
# include <locale.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

# define BUF_SIZE	4096
# define FLAGS		"+ 0-#"
# define NUMBERS	"0123456789"
# define SPECIFIERS	"cspdoiuxX%"
# define LOW_BASE	"0123456789abcdef"
# define UP_BASE	"0123456789ABCDEF"
# define OK			0
# define ERROR		-1
# define MALLOC_ERROR	-1337
# define PARSE_ERROR	-42

typedef struct s_format
{
	bool	left_just;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero_pad;
	char	specifier;
	int		width_val;
	int		prec_val;
	size_t	base;
	size_t	padding_spaces;
	int		padding_zeros;
	bool	signed_value;
	int		is_negative;
	int		is_converted;
	bool	upper_case;
	char	buf_tmp[64];
	int		num_len;
}	t_format;

typedef struct s_data
{
	const char	*s;	// pointer copy to fmt
	char		*buf; // 4096 in a HEAP
	va_list		ap; //va_list -> va_arg(ap, int);
	size_t		chars_written;
	size_t		buf_index;
	size_t		spec_num;
	t_format	fmt;
}	t_data;

/**********************************PRINTF***********************************/
int		ft_printf(const char *format, ...);

/***********************************PRINT***********************************/
void	print_char(t_data *data, int c);
void	print_str(t_data *data, char *str);
void	print_digit(t_data *data, long int int_val);
void	print_pointer(t_data *data, size_t int_val);
void	put_sign(t_data *data);

/***********************************BUFFER***********************************/
void	write_buf(t_data *data, char c);
void	flush_buf(t_data *data);
void	putchar_buf_n(char c, int precision, t_data *data);
void	putstr_buf_n(char *s, int precision, t_data *data);

/*********************************UTILITIES**********************************/
bool	inside(const char *s, char c);
int		partial_init(t_data *data);
int		get_format(t_data *data);
//int		ft_strcmp(const char *s1, const char *s2);
int		was_neg(t_data *data);
//size_t	ft_strlen(const char *s);
//void	*ft_memset(void *s, int c, size_t n);
void	itoa_base(t_data *data, unsigned int int_val);

#endif
