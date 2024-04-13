# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apirusov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 18:10:48 by apirusov          #+#    #+#              #
#    Updated: 2024/04/09 14:30:29 by apirusov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRCDIR= .
#SRC= $(wildcard $(SRCDIR)/*.c)
SRC = ft_atoi.c ft_putendl_fd.c ft_strlcat.c ft_bzero.c \
  	  ft_puterror.c ft_strlcpy.c ft_calloc.c ft_putnbr.c ft_strlen.c \
	  ft_isalnum.c ft_putnbr_fd.c ft_isalpha.c ft_putstr.c ft_strncmp.c \
	  ft_isascii.c ft_putstr_fd.c ft_strncpy.c ft_isdigit.c ft_memchr.c \
  	  ft_recursive_power.c ft_strnstr.c ft_islower.c ft_memcmp.c ft_split.c \
	  ft_strrchr.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strtrim.c \
	  ft_isupper.c ft_memmove.c ft_strcmp.c ft_substr.c ft_itoa.c ft_memset.c \
	  ft_strcpy.c ft_tohex.c ft_numlen.c ft_strdup.c ft_tolower.c ft_putchar.c \
  	  ft_striteri.c ft_toupper.c ft_putchar_fd.c ft_strjoin.c ft_strmapi.c

OBJS= $(SRC:.c=.o)
HEAD = ./includes/
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
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

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_O)

clean:
	${RM} ${OBJS} ${BONUS_O}

fclean: clean
	${RM} ${NAME}

re: fclean all

rebonus: fclean bonus
.PHONY: all clean fclean re bonus rebonus

