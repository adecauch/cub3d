# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 13:32:49 by adecauch          #+#    #+#              #
#    Updated: 2026/02/22 16:21:25 by ramahrez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = Cub3D
CC = cc
# J'ai ajoute fsanitize ici pour ton debuggage
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
UNAME_S = $(shell uname -s)

# Variables pour le testeur
TESTER_DIR = tester_cub3D
TESTER_URL = https://github.com/rmahrez19/tester_cub3D.git

ifeq ($(UNAME_S),Darwin)
	CFLAGS += -DGL_SILENCE_DEPRECATION
	MLX_DIR = inc/mlx_macos
	LIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	CLEANUP_SRC = src/engine/cleanup_macos.c
	MOUSE_SRC = src/engine/mouse_macos.c
else
	MLX_DIR = inc/mlx_linux
	LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
	CLEANUP_SRC = src/engine/cleanup_linux.c
	MOUSE_SRC = src/engine/mouse_linux.c
endif

SRCS = src/main.c \
       src/engine/game.c \
       $(CLEANUP_SRC) \
       $(MOUSE_SRC) \
       src/engine/key_handler.c \
       src/engine/render.c \
       src/engine/minimap/minimap.c \
       src/engine/minimap/minimap_utils.c \
       src/engine/cleanup_linux_utils.c \
       src/engine/raycasting/raycasting.c \
       src/engine/raycasting/ray_init.c \
       src/engine/raycasting/ray_dda.c \
       src/engine/raycasting/ray_render.c \
       src/engine/player_movement.c \
       src/engine/door.c \
       src/engine/collectible.c \
       src/engine/sprite/sprite_init.c \
       src/engine/sprite/sprite_render.c \
       src/engine/sprite/sprite_anim.c \
       src/engine/sprite/sprite_utils.c \
       src/engine/sprite/placeholder_tex.c \
       src/engine/slenderman/slender_init.c \
       src/engine/slenderman/slender_move.c \
       src/engine/slenderman/slender_anim.c \
       src/engine/slenderman/slender_render.c \
       src/parsing/init_data.c \
       src/parsing/verif_door.c \
       src/libft/ft_atoi.c \
       src/libft/ft_bzero.c \
       src/libft/ft_isdigit.c \
       src/libft/ft_memcpy.c \
       src/libft/ft_memset.c \
       src/libft/ft_putstr.c \
       src/libft/ft_realloc.c \
       src/libft/ft_tabdup.c \
       src/libft/ft_strchr.c \
       src/libft/ft_strdup.c \
       src/libft/ft_strlen.c \
       src/libft/ft_strncmp.c \
       src/libft/get_next_line_bonus.c \
       src/libft/print_error.c \
       src/libft/ft_strtrim.c \
       src/libft/ft_substr.c \
       src/parsing/extract_color.c \
       src/parsing/extract_config.c \
       src/parsing/extract_config_utils.c \
       src/parsing/extract_map_data.c \
       src/parsing/extract_player_data.c \
       src/parsing/parsing.c \
       src/parsing/read_file.c \
       src/parsing/string_utils.c \
       src/parsing/verif_file.c \
       src/parsing/verif_map.c

INC = -I$(MLX_DIR) -Iinc -Iinc/struct -Iinc/keybind

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(RED)Removed object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(TESTER_DIR) .test_out
	@echo "$(RED)Removed executable and test files$(RESET)"

re: fclean all

test: all
	@echo "$(GREEN)Vérification du testeur...$(RESET)"
	@if [ ! -d "$(TESTER_DIR)" ]; then \
		git clone $(TESTER_URL) $(TESTER_DIR); \
	fi
	@echo "$(GREEN)Lancement des tests...$(RESET)"
	@bash $(TESTER_DIR)/test_maps.sh

.PHONY: all clean fclean re test