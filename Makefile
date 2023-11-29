# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:08:16 by qraymaek          #+#    #+#              #
#    Updated: 2023/11/28 23:18:06 by qraymaek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Basics
NAME = pipex
INCLUDES = include
SRCS_DIR = src
OBJS_DIR = objs
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
LIBFT = libft

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources
SOURCES = pipex.c get_next_line.c get_next_line_utils.c utils.c error.c

SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(BLUE)"
	@make -C $(LIBFT)

tmp:
	@mkdir -p objs

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -L $(LIBFT) -o $@ $^ -lft -lm
	@echo "$(GREEN)Project successfully compiled"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

clean:
	@echo "$(RED)Deleting object files$(BLUE)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJS_DIR)

fclean:
	@echo "$(RED)Deleting all files including executables$(BLUE)"
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(MAGENTA)All the files are now cleaned with fclean"

re: fclean
	@$(MAKE) all -j

.PHONY: tmp, re, fclean, clean
