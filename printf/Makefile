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
SRC = ft_printf.c buffer.c utilities.c parse.c print_cs.c print_num.c ft_strlen.c main.c
OBJS = $(SRC:.c=.o)
HEAD = ./includes/

CC = cc
CFLAGS = -Wall -Werror -Wextra -c
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib
#BONUS_O= ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}

.c.o:
	${CC} ${CFLAGS} $< -I ${HEAD} -o ${<:.c=.o}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean:
	${RM} ${OBJS} ${BONUS_O}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re 
