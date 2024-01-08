# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 13:48:27 by tday              #+#    #+#              #
#    Updated: 2023/10/02 22:43:48 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		= fdf
GNL_DIR		= get_next_line
LFT_DIR		= libft
MLX_DIR 	= mlx
INC_DIR		= includes
SRC_DIR		= sources
GNL_LIB		= $(GNL_DIR)/libgnl.a
LFT_LIB		= $(LFT_DIR)/libft.a
MLX_LIB 	= $(MLX_DIR)/libmlx.a
SRC_FILES	= main.c initialisation.c read_map.c key_down.c key_up.c events.c \
			  frame_image.c colours.c colour_gradient.c bresenham.c wu.c \
			  wu_lines.c grid.c isometric_rotate.c
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(SRCS:%.c=%.o)
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)
AR			= ar -rcs
RM			= rm -f

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

$(NAME): $(OBJS) $(GNL_LIB) $(LFT_LIB) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJS) -L$(GNL_DIR) -lgnl -L$(LFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(CYAN)Everything compiled and linked into executable: $(BLUE)fdf$(DEFAULT_COLOUR)"

$(GNL_LIB):
	@$(MAKE) all -s -C $(GNL_DIR)
	@echo "\n"

$(LFT_LIB):
	@$(MAKE) -s -C $(LFT_DIR)
	@echo "\n"

$(MLX_LIB):
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(DEFAULT_COLOUR)"

objclean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)sources object files deleted.$(DEFAULT_COLOUR)"

clean: objclean
	@$(MAKE) clean -s -C $(GNL_DIR)
	@echo "$(RED)cleaned gnl.$(DEFAULT_COLOUR)"
	@$(MAKE) clean -s -C $(LFT_DIR)
	@echo "$(RED)cleaned libft.$(DEFAULT_COLOUR)"
	@$(MAKE) clean -s -C $(MLX_DIR)
	@echo "$(RED)cleaned mlx.$(DEFAULT_COLOUR)"

fclean: objclean
	@$(MAKE) fclean -s -C $(GNL_DIR)
	@echo "$(RED)fcleaned gnl.$(DEFAULT_COLOUR)"
	@$(MAKE) fclean -s -C $(LFT_DIR)
	@echo "$(RED)fcleaned libft.$(DEFAULT_COLOUR)"
	@$(MAKE) fclean -s -C $(MLX_DIR)
	@echo "$(RED)fcleaned mlx.$(DEFAULT_COLOUR)"
	@$(RM) $(NAME)
	@echo "$(YELLOW)Deleted executable: $(WHITE)$(NAME).$(DEFAULT_COLOUR)"

re: fclean all

.PHONY: all objclean clean fclean re