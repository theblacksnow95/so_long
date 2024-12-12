/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:16:16 by emurillo          #+#    #+#             */
/*   Updated: 2024/12/12 14:17:40 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 gcc compilator
 gcc -Wall -Wextra -Werror -I../../minilibx-linux test_main.c -L../../minilibx-linux -lmlx -lXext -lX11 -lm
 */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define BACKGROUND_IMG "../../images/cover/TX-Tileset-Grass.xpm"
#define MLX_ERROR 1

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
} 			t_data;

int	handle_mouseclick(int button, int x, int y, void *param)
{
	(void)param;
	printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);
	return (0);
}

int	handle_close(void *param)
{
	(void)param;
	printf("Window closed. Exiting...\n");
	exit(0);
	return (0);
}


int	handle_keypress(int keycode)
{
	printf("key pressed: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("ESC key pressed, exiting...\n");
		handle_close(NULL);
	}
	return (0);
}

int	render_frame(t_data *data)
{
	int x;
	int y;

	mlx_clear_window(data->mlx, data->win);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
			x += data->img_width;
		}
		y += data->img_height;
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Test Window");
	if (!data.win)
	{
		free(data.win);
		return (MLX_ERROR);
	}
	printf("Window created\n");
	data.img = mlx_xpm_file_to_image(data.mlx, BACKGROUND_IMG, &data.img_width, &data.img_height);
	if (!data.img)
		return (printf("error reading img\n"));
	else
		printf("Image loaded\n");
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_key_hook(data.win, handle_keypress, NULL);
	mlx_mouse_hook(data.win, handle_mouseclick, NULL);
	mlx_hook(data.win, 17, 0L, handle_close, NULL);
/* 	mlx_hook(mlx_win, 4, 1L << 2, handle_mouseclick, NULL); */
	mlx_loop(data.mlx);
}
