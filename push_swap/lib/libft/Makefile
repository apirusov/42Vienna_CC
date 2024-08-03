# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apirusov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 18:10:48 by apirusov          #+#    #+#              #
#    Updated: 2024/04/25 14:55:18 by apirusov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

DIR_SRCS = srcs
DIR_OBJS = objs
HEAD = includes
SUBDIRS = is mem str to lst math put

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEAD) -O3 -g
AR = ar rcs
RM = /bin/rm -f
LIB = ranlib

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
	@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(LIB) $(NAME)
	@echo "\033[1;32m[$(NAME)] Library created successfully.\033[0m"

clean:
	$(RM) $(OBJS)
	$(RM) -r $(DIR_OBJS)
	@echo "\033[1;33m[$(NAME)] Object files removed successfully.\033[0m"	

fclean: clean
	$(RM) $(NAME)
	@echo "\033[1;33m[$(NAME)] Library removed successfully.\033[0m"

re: fclean all

.SILENT:
.PHONY: all clean fclean re bonus rebonus