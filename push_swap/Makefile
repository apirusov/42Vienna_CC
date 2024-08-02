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

# Directories
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./includes

# Directories
SRC_DIR = ./srcs
OBJ_DIR = ./bin
HEAD = ./includes

# Libraries
LIBFT_DIR = ./lib/Libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/includes

PRINTF_DIR = ./lib/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = $(PRINTF_DIR)/includes

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Archiver and other tools
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib

# Main target
all: $(NAME)

# Link libraries and create the executable
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

# Rule to create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(HEAD) -I $(LIBFT_INC) -I $(PRINTF_INC) -c $< -o $@

# Libraries compilation
$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

# Clean up object files
clean:
	$(RM) $(OBJ_DIR)/*.o
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

# Full clean, including the library
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

# Rebuild everything
re: fclean all
remake: fclean all

.PHONY: all clean fclean re

