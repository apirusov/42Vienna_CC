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
SRC_DIR = ./srcs
OBJ_DIR = ./objs
HEAD = ./includes/

# Libraries
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/includes
LIBFT_OBJ_DIR = $(LIBFT_DIR)/objs
LIBFT_SUBDIRS = is mem str to lst math put

# Source and object files
PRINTF_SRCS = $(wildcard $(SRC_DIR)/*.c)
LIBFT_SRCS = $(foreach dir, $(LIBFT_SUBDIRS), $(wildcard $(LIBFT_DIR)/srcs/$(dir)/*.c))

PRINTF_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(PRINTF_SRCS))
LIBFT_OBJS = $(foreach dir, $(LIBFT_SUBDIRS), $(patsubst $(LIBFT_DIR)/srcs/$(dir)/%.c, $(LIBFT_OBJ_DIR)/$(dir)/%.o, $(wildcard $(LIBFT_DIR)/srcs/$(dir)/*.c)))

# Archiver and other tools
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(HEAD) -I$(LIBFT_INC) -O3 -g
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib
NORM = norminette

MAKE_LIB = make --no-print-directory -s -C

# Main target
all: $(OBJ_DIR) $(LIBFT) $(NAME)
	@echo "\033[1;32m[$(NAME)] created successfully.\033[0m"

# Create directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(foreach dir, $(LIBFT_SUBDIRS), $(LIBFT_OBJ_DIR)/$(dir))

# Rule to create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_OBJ_DIR)/%/%.o: $(LIBFT_DIR)/srcs/%/%.c | $(OBJ_DIR)
	@mkdir -p $(LIBFT_OBJ_DIR)/$*
	$(CC) $(CFLAGS) -c $< -o $@

# Libraries compilation
$(LIBFT): 
	@$(MAKE_LIB) $(LIBFT_DIR)

# Create the static library
$(NAME): $(PRINTF_OBJS) $(LIBFT_OBJS)
	$(AR) $@ $^
	$(LIB) $@

# Clean up object files
clean: lib_clean
	$(RM) -r $(OBJ_DIR)
	@echo "\033[1;33m[$(NAME)] Object files removed.\033[0m"

lib_clean:
	@$(MAKE_LIB) $(LIBFT_DIR) clean
	@echo "\033[1;33m[$(NAME)] Object files removed.\033[0m"

lib_fclean:
	@$(MAKE_LIB) $(LIBFT_DIR) fclean
	@echo "\033[1;33m[$(NAME)] Library removed.\033[0m"

# Full clean, including the library
fclean: clean lib_fclean
	$(RM) $(NAME)
	@echo "\033[1;33m[$(NAME)] Library removed successfully.\033[0m"

# Rebuild everything
re: fclean all

# Remake rule (same as re)
remake: re

.SILENT:
.PHONY: all clean fclean re remake