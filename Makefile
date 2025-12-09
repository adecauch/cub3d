# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 09:10:07 by adecauch          #+#    #+#              #
#    Updated: 2025/12/09 20:43:11 by adecauch         ###   ########.fr        #
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
	   src/engine/render_menu.c

INC = -I$(MLX_DIR) -Iinc
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
