# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 23:27:34 by adecauch          #+#    #+#              #
#    Updated: 2025/12/08 21:15:53 by hectordavro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = Cube3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

UNAME_S     = $(shell uname -s)

# Codes ANSI pour la couleur verte et la réinitialisation
GREEN       = \033[32m
RESET       = \033[0m

# ---------------- INC ---------------- #

INC_DIR     = inc
INC         = -I$(INC_DIR) \
              -I$(INC_DIR)/struct \
              -I$(INC_DIR)/keybind \
              -I$(MLX_DIR)

# ---------------- MLX ---------------- #

ifeq ($(UNAME_S),Darwin)
	CFLAGS  += -DGL_SILENCE_DEPRECATION
	MLX_DIR = inc/mlx_macos
	LIBS    = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = inc/mlx_linux
	LIBS    = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

# ---------------- SRC / OBJ ---------------- #

SRC_DIR     = src
OBJ_DIR     = obj

# Calcule les chemins complets des sources
SRCS        = $(shell find $(SRC_DIR) -name "*.c")

# Calcule les chemins complets des objets (ex: obj/utils/file.o)
OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Extrait les dossiers nécessaires à créer (ex: obj/utils/)
DIRS        = $(sort $(dir $(OBJS)))

# ---------------- RULES --------------- #

all: $(NAME)

# Cible principale : dépend de la création des dossiers et des fichiers objets
$(NAME): $(DIRS) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)✅ Successfully created executable: $(NAME)$(RESET)"

# Règle pour créer récursivement les dossiers objets (masquée)
$(DIRS):
	@mkdir -p $@

# Règle de compilation générique (masquée)
$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(DIRS)