# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 23:27:34 by adecauch          #+#    #+#              #
#    Updated: 2025/04/22 23:27:37 by adecauch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    CFLAGS += -DGL_SILENCE_DEPRECATION
    MLX_DIR = mlx_macos
    LIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_DIR = mlx_linux
    LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

INC = -I$(MLX_DIR)

SRCS = so_long.c \
	   game/game.c \
	   game/game_utility.c \
	   game/drawing.c \
	   game/drawing_utility.c \
	   parsing/parsing.c \
	   parsing/parsing_utility_one.c \
	   parsing/parsing_utility_two.c \
	   parsing/flood_fill.c \
	   libft/get_next_line.c \
	   libft/ft_itoa.c \
	   libft/libft.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
