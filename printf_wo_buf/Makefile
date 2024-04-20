# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apirusov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 17:42:12 by apirusov          #+#    #+#              #
#    Updated: 2024/04/16 11:36:00 by apirusov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = .
SRC = ft_printf.c \
	buffer.c \
	utilities.c \
	parse.c \
	print_cs.c \
	print_num.c \
	print_nil.c
OBJS = $(SRC:.c=.o)
HEAD = ./includes/
BONUS =  ft_printf.c \
	buffer.c \
	utilities.c \
	parse.c \
	print_cs.c \
	print_num.c \
	print_nil.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -c
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib
BONUS_O= ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}

.c.o:
	${CC} ${CFLAGS} $< -I ${HEAD} -o ${<:.c=.o}

bonus: ${NAME} ${BONUS_O} ${OBJS}
		${AR} ${NAME} ${BONUS_O}
		${AR} ${NAME} ${OBJS}
		${LIB} ${NAME}

clean:
	${RM} ${OBJS} ${BONUS_O}

fclean: clean
	${RM} ${NAME}

re: fclean all

rebonus: fclean bonus
.PHONY: all clean fclean re bonus rebonus
