NAME = so_long
SRC = utils/so_long.c utils/init_game.c utils/read_map.c \
	  utils/render_textures.c utils/exit_game.c \
	  utils/map_validation.c utils/movement.c utils/check_moves.c \
	  utils/path_validation.c
MLX_DIR_LINUX = minilibx-linux
MLX_DIR_MAC = minilibx_opengl_20191021
LIBFT_DIR = libft
CFLAGS = -Wall -Werror -Wextra -I$(MLX_DIR) -I$(LIBFT_DIR)
CC= gcc

UNAME_S := $(shell uname -s)

LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB_LINUX = $(MLX_DIR_LINUX)/libmlx.a
MLX_LIB_MAC = $(MLX_DIR_MAC)/libmlx.a


ifeq ($(UNAME_S), Linux)
	MLX_DIR = $(MLX_DIR_LINUX)
	MLX_LIB = $(MLX_LIB_LINUX)
	LFLAGS = -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lXext -lX11 -lm -lft
else ifeq ($(UNAME_S), Darwin)
	MLX_DIR = $(MLX_DIR_MAC)
	MLX_LIB = $(MLX_LIB_MAC)
	LFLAGS = -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lXext -lX11 -lm -lft
endif


OBJ = $(SRC:.c=.o)

TARGET = so_long

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

$(LIBFT_LIB):
	@echo "Building libft library..."
	@$(MAKE) bonus -C $(LIBFT_DIR)

$(MLX_LIB):
	@echo "Building minilibx library..."
	@$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: clean all

.PHONY: all clean fclean re
