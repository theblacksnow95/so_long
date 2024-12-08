NAME = window_example
SRC = test_main.c
LFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror -I$(MLX_INC)
MLX_DIR = ../../minilibx_opengl_20191021
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = $(MLX_DIR)
CC = gcc

all: $(NAME)

$(NAME): $(SRC) $(MLX_LIB)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LFLAGS)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re
