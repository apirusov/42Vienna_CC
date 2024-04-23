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
#SRC = ft_atoi.c ft_putendl_fd.c ft_strlcat.c ft_bzero.c \
  	  ft_puterror.c ft_strlcpy.c ft_calloc.c ft_putnbr.c ft_strlen.c \
	  ft_isalnum.c ft_putnbr_fd.c ft_isalpha.c ft_putstr.c ft_strncmp.c \
	  ft_isascii.c ft_putstr_fd.c ft_strncpy.c ft_isdigit.c ft_memchr.c \
  	  ft_recursive_power.c ft_strnstr.c ft_islower.c ft_memcmp.c ft_split.c \
	  ft_strrchr.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strtrim.c \
	  ft_isupper.c ft_memmove.c ft_strcmp.c ft_substr.c ft_itoa.c ft_memset.c \
	  ft_strcpy.c ft_tohex.c ft_numlen.c ft_strdup.c ft_tolower.c ft_putchar.c \
  	  ft_striteri.c ft_toupper.c ft_putchar_fd.c ft_strjoin.c ft_strmapi.c

DIR_SRCS = srcs
SUBDIRS = is mem str to lst math put
DIR_OBJS = bin

SRCS_PATH = $(addprefix $(DIR_SRCS)/, $(SUBDIRS))
SRCS = $(foreach dir, $(SRCS_PATH), $(wildcard $(dir)/*.c))
OBJS = $(patsubst $(DIR_SRCS)/%.c, $(DIR_OBJS)/%.o, $(SRCS))
#OBJS= $(SRC:.c=.o)
HEAD = ./includes/
BONUS = $(wildcard $(DIR_SRCS)/, lst/*.c)
BONUS_O = $(patsubst $(DIR_SRCS)/%.c, $(DIR_OBJS)/%.o, $(BONUS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib

all: ${NAME}

${NAME}: ${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}
.c.o:
	${CC} ${CFLAGS} $< -I ${HEAD} -o ${<:.c=.o}

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

bonus: ${NAME} ${BONUS_O} ${OBJS}
		${AR} ${NAME} ${BONUS_O}
		${AR} ${NAME} ${OBJS}
		${LIB} ${NAME}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS_PATH)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_O)

clean:
	${RM} ${OBJS} ${BONUS_O}

fclean: clean
	${RM} ${NAME}

re: fclean all

rebonus: fclean bonus
.PHONY: all clean fclean re bonus rebonus

