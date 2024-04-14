/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:39:58 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/13 15:21:30 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <limits.h>
# include <locale.h>
//# include <libexplain/malloc.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

# define	BUF_SIZE (1<<12)

# define FLAGS		"+ 0-#"
# define NUMBERS	"0123456789"
# define SPECIFIERS	"cspdobiuxX%"

typedef union 

typedef enum {
	OK = 0,
	ERROR = -1,
	MALLOC_ERROR = -1337,
	PARSE_ERROR = -42,
	FALSE = false,
	TRUE = true,
} e_error;

typedef enum {
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,
}	e_base;

typedef struct s_format {
	bool	left_just;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero_pad;
	char	specifier;
	int		width_val;
	int		precision_val;
	e_base	base;
	size_t	padding_spaces;
}	t_format;

typedef struct s_data {
	const char	*s;	// pointer copy to fmt
	va_list		ap; //va_list -> va_arg(ap, int);
	size_t		chars_written;
	char		*buf; // 4096 in a HEAP
	size_t		buf_index;
	t_format	format;
}	t_data;

int ft_atoi(const char *str);
int ft_printf(const char *format, ...);
int get_format(t_data *data);
size_t	ft_strlen(const char *s);
void	*ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	write_buf(t_data *data, char c);
void	flush_buf(t_data *data);
void    putchar_buf_n(char c, int precision, t_data *data);
void	print_char(t_data *data, int c);
void    putcstr_buf_n(char *s, int precision, t_data *data);

#endif
