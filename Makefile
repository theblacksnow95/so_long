NAME = prototype_v0
SRC = utils/main.c utils/init_game.c utils/read_map.c utils/render_textures.c utils/exit_game.c
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Werror -Wextra -I$(MLX_DIR) -I$(LIBFT_DIR)
LFLAGS = -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lXext -lX11 -lm -lft
CC= gcc

OBJ = $(SRC:.c=.o)

TARGET = prototype_v0

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean

	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
