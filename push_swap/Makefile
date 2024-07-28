# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apirusov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 14:08:37 by apirusov          #+#    #+#              #
#    Updated: 2024/07/28 14:08:38 by apirusov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

# Sources
SRC_DIR = ./srcs
OBJ_DIR = ./bin

SRC = push_swap \
		push_swap_init \
		stack_init \
		stack_utils \
		push_cmds \
		swap_cmds \
		rotate_cmds \
		rotate_utils \
		rev_rotate_cmds \
		free_error \
		tiny_sort
SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
BONUSES = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))

OBJS = $(SRCS:.c=.o)
BONUS_O = $(BONUSES:.c=.o)
HEAD = ./includes/

# Libraries
LIBFT = libft.a
LIBFT_DIR = ./lib/Libft
LIBFT_FILE = $(addprefix $(LIBFT_DIR)/, $(LIBFT))
CFLAGS += -I $(LIBFT_DIR)/includes

FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ./lib/printf
FT_PRINTF_FILE = $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF))
CFLAGS += -I $(FT_PRINTF_DIR)/includes


CC = gcc
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
