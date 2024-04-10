# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apirusov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 18:10:48 by apirusov          #+#    #+#              #
#    Updated: 2024/04/09 17:57:59 by apirusov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

CUR_DIR= .
DIR_SRCS= srcs
DIR_OBJS= bin
SUBDIRS= is mem put str to lst math

SRCS_DIRS = $(addprefix $(DIR_SRCS)/,$(SUBDIRS))
SRCS= $(foreach dir, $(SRCS_DIRS),$(wildcard $(dir)/*.c))
OBJS= $(patsubst $(DIR_SRCS)/%.c,$(DIR_OBJS)/%.o, $(SRCS))

#SRCS_DIR = $(shell find $(DIR_SRCS) -type f -name *.c)
#OBJS = $(patsubst $(DIR_SRCS)/%, $(DIR_OBJS)/%, $(SRCS_DIR:.c=.o))

HEAD = ./includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib

all: ${NAME}

${DIR_OBJS}/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	${CC} ${CFLAGS} -I ${HEAD} -c $< -o $@ 

#.c.o:
#	${CC} ${CFLAGS} -I ${HEAD} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}
clean:
	${RM} ${OBJS}
#	${RM} -r ${DIR_OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
