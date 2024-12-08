NAME = window_example
SRC = test_main.c
MLX_DIR = ../../minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
CFLAGS = -Wall -Werror -Wextra -I$(MLX_DIR)
LFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
CC= gcc

TARGET = window_example

all: $(NAME)


$(NAME): $(SRC) $(MLX_LIB)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LFLAGS)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all


.PHONY: all clean fclean re
