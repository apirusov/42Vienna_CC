/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:39:58 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/17 19:12:50 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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
# define SPECIFIERS	"cspdobiuxX%"
# define LOW_BASE	"0123456789abcdef"
# define UP_BASE	"0123456789ABCDEF"
# define OK			0
# define ERROR		-1
# define MALLOC_ERROR	-1337
# define PARSE_ERROR	-42

typedef union
{
	unsigned long	uint64;
	long			int64;
} onion;

typedef struct base
{
	BASE_2 = 2;
	BASE_8 = 8;
	BASE_10 = 10;
	BASE_16 = 16;
}	t_base;

typedef struct s_format
{
	bool	left_just;
	int		plus;
	int		space;
	bool	hash;
	int		zero_pad;
	char	specifier;
	int		width_val;
	int		prec_val;
	t_base	base;
	size_t	padding_spaces;
	int		padding_zeros;
	bool	signed_value;
	bool	is_negative;
	bool	is_converted;
	bool	upper_case;
	char	buf_tmp[64];
	int		num_len;
}	t_format;

typedef struct s_data
{
	const char	*s;	// pointer copy to fmt
	va_list		ap; //va_list -> va_arg(ap, int);
	size_t		chars_written;
	char		*buf; // 4096 in a HEAP
	size_t		buf_index;
	t_format	fmt;
}	t_data;

bool	inside(const char *s, char c);
//int my_atoi(t_data *data);
int		ft_printf(const char *format, ...);
int		get_format(t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	write_buf(t_data *data, char c);
void	flush_buf(t_data *data);
void	putchar_buf_n(char c, int precision, t_data *data);
void	print_char(t_data *data, int c);
void	print_str(t_data *data, char *str);
void	putstr_buf_n(char *s, int precision, t_data *data);
void	itoa_base(t_data *data, onion int_val);
//void    set_padding_spaces(t_data *data);
//void	set_padding_zeros(t_data *data);
void	print_digit(t_data *data, onion int_val);
void	render_format(t_data *data, char specifier);
void	nil_my_ptr(t_data *data);

#endif
