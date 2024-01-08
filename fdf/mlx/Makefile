# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 13:44:32 by tday              #+#    #+#              #
#    Updated: 2023/09/10 13:52:30 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME	= libmlx.a
SRCS	= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m\
		 mlx_xpm.c mlx_int_str_to_wordtab.c
OBJSC	= $(SRCS:.c=.o)
OBJS	= $(OBJSC:.m=.o)
CC 		= cc
CFLAGS	= -O2 -DGL_SILENCE_DEPRECATION -Wno-deprecated-declarations
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

%.o: %.m
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(DEFAULT_COLOUR)"

clean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)mlx object files deleted.$(DEFAULT_COLOUR)"

fclean: clean
	@$(RM) $(NAME) mlx_app
	@echo "$(MAGENTA)$(NAME) and mlx_app deleted.$(DEFAULT_COLOUR)"

re: fclean all

# Phony

.PHONY: all clean fclean re
