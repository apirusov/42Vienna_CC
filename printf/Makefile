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
SRC = ft_printf \
	buffer \
	utilities \
	parse \
	print_cs \
	print_num \
	print_ptr
SRCS = $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRC)))
BONUSES = $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRC)))

OBJS = $(SRCS:.c=.o)
BONUS_O= ${BONUSES:.c=.o}
HEAD = ./includes/

CC = cc
CFLAGS = -Wall -Werror -Wextra -c
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib

all: ${NAME}

${NAME}: ${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}

.c.o:
	${CC} ${CFLAGS} $< -I ${HEAD} -o ${<:.c=.o}

bonus: ${NAME} ${BONUS_O} 
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
