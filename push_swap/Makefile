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

CHECKER = checker
PUSH_SWAP = push_swap
NAME = $(PUSH_SWAP) $(CHECKER)

# Directories
PUSH_SWAP_DIR = ./srcs/push_swap
CHECKER_DIR = ./srcs/checker
OBJ_DIR = ./objs
HEAD = ./includes

# Libraries
LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/includes

PRINTF_DIR = ./lib/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = $(PRINTF_DIR)/includes

LFT_FLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# Source and object files
PUSH_SWAP_SRCS = $(wildcard $(PUSH_SWAP_DIR)/*.c)
CHECKER_SRCS = $(wildcard $(CHECKER_DIR)/*.c)
PUSH_SWAP_OBJS = $(patsubst $(PUSH_SWAP_DIR)/%.c, $(OBJ_DIR)/push_swap/%.o, $(PUSH_SWAP_SRCS))
CHECKER_OBJS = $(patsubst $(CHECKER_DIR)/%.c, $(OBJ_DIR)/checker/%.o, $(CHECKER_SRCS))

# Archiver and other tools
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEAD) -I$(LIBFT_INC) -I$(PRINTF_INC) -O3 -g
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib
NORM = norminette

MAKE_LIB = make --no-print-directory -s -C

# Main target
all: $(PUSH_SWAP)
	@echo "\033[1;32m[$(PUSH_SWAP)] created successfully.\033[0m"

bonus: $(CHECKER)
	@echo "\033[1;32m[$(CHECKER)] created successfully.\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/push_swap
	@mkdir -p $(OBJ_DIR)/checker

$(OBJ_DIR)/push_swap/%.o: $(PUSH_SWAP_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/checker/%.o: $(CHECKER_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Libraries compilation
$(LIBFT): 
	@$(MAKE_LIB) $(LIBFT_DIR)

$(PRINTF): 
	@$(MAKE_LIB) $(PRINTF_DIR)

LIBRARIES = $(LIBFT) $(PRINTF)

$(PUSH_SWAP): $(PUSH_SWAP_OBJS) $(LIBRARIES)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIBRARIES) -o $(PUSH_SWAP)

$(CHECKER): $(CHECKER_OBJS) $(LIBRARIES)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS)  $(LIBRARIES) -o $(CHECKER)

lib_clean:
	@$(MAKE_LIB) $(LIBFT_DIR) clean
	@$(MAKE_LIB) $(PRINTF_DIR) clean
	@echo "\033[1;33m[$(NAME)] Object files removed.\033[0m"

lib_fclean:
	@$(MAKE_LIB) $(LIBFT_DIR) fclean
	@$(MAKE_LIB) $(PRINTF_DIR) fclean
	@echo "\033[1;33m[$(NAME)] Library removed.\033[0m"

# Clean up object files
clean: lib_clean
	$(RM) -r $(OBJ_DIR)
	@echo "\033[1;33m[$(NAME)] Object files removed.\033[0m"

# Full clean, including the library
fclean: clean lib_fclean
	@$(RM) $(NAME)
	@echo "\033[1;33m[$(NAME)] removed.\033[0m"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re