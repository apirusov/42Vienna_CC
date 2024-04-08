# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apirusov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 18:10:48 by apirusov          #+#    #+#              #
#    Updated: 2024/04/05 13:33:43 by apirusov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRCDIR= .
SRC= $(wildcard $(SRCDIR)/*.c)
OBJS= $(SRC:.c=.o)
HEAD = ./includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} $< -I ${HEAD} -o ${<:.c=.o}

${NAME}: ${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
.PHONY: all clean fclean re
