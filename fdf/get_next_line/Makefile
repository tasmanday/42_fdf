# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 17:52:06 by tmitchel          #+#    #+#              #
#    Updated: 2023/09/10 13:53:18 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME	= libgnl.a
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:%.c=%.o)
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs
RM		= rm -f	

# Colours

DEFAULT_COLOUR = \033[0m
GRAY = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

# Recipes

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(CYAN)$(NAME) compiled successfully!$(DEFAULT_COLOUR)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(DEFAULT_COLOUR)"

clean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)gnl object files deleted.$(DEFAULT_COLOUR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)$(NAME) deleted.$(DEFAULT_COLOUR)"

re: fclean all

# Phony

.PHONY: all clean fclean re txt