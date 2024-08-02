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

# Directories
SRCDIR = .
SRC_DIR = ./srcs
OBJ_DIR = ./bin
HEAD = ./includes/

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CC = cc
CFLAGS += -Wall -Werror -Wextra -c
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib

all: ${NAME}

${NAME}: ${OBJS}
	$(AR) $@ $^
	$(LIB) $@

# Rule to create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

#.c.o:
#	${CC} ${CFLAGS} $< -I ${HEAD} -o ${<:.c=.o}

clean:
	${RM} ${OBJ_DIR}/*.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus rebonus
