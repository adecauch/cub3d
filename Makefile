# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 09:10:07 by adecauch          #+#    #+#              #
#    Updated: 2025/12/10 18:19:13 by hectordavro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = Cube3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    CFLAGS += -DGL_SILENCE_DEPRECATION
    MLX_DIR = inc/mlx_macos
    LIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_DIR = inc/mlx_linux
    LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

SRCS = src/main.c \
	   src/engine/game.c \
	   src/engine/key_handler.c \
	   src/engine/render_game.c \
	   src/engine/render_menu.c \
	   src/init_data.c \
	   src/debug/debug_utils.c \
	   src/debug/print_data.c \
	   src/libft/ft_atoi.c \
	   src/libft/ft_bzero.c \
	   src/libft/ft_isdigit.c \
	   src/libft/ft_memcpy.c \
	   src/libft/ft_memset.c \
	   src/libft/ft_putstr.c \
	   src/libft/ft_realloc.c \
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
	   src/parsing/extract_map_data.c \
	   src/parsing/parsing.c \
	   src/parsing/read_file.c \
	   src/parsing/string_utils.c \
	   src/parsing/verif_file.c \
	   src/parsing/verif_file_2.c \
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
	@echo "$(RED)Removed executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re
