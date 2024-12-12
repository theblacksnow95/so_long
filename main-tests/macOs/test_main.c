/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:16:16 by emurillo          #+#    #+#             */
/*   Updated: 2024/12/12 13:17:27 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
}			t_data;

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
	if (keycode == 53)
	{
		printf("ESC key pressed, exiting...\n");
		exit(0);
	}
	return (0);
}

int	handle_mouseclick(int button, int x, int y, void *param)
{
	(void)param;
	printf("Mouse button %d, pressed at (%d, %d)\n", button, x, y);
	return (0);
}

int	render_frame(t_data *data)
{
	int	x;
	int	y;

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
	char	*path_texture;

	path_texture = "../../images/tests/TX Tileset Grass.png";
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Test Window");
	if (!data.win)
		return (1);
	printf("Window created.\n");
	data.img = mlx_png_file_to_image(data.mlx, path_texture, &data.img_width, \
	&data.img_height);
	if (!data.img)
		return (printf("Error reading img.\n"));
	else
		printf("Image loaded.\n");
	mlx_put_image_to_window(data.mlx, data.win, data.img, 1, 1);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_key_hook(data.win, handle_keypress, NULL);
	mlx_hook(data.win, 17, 0L, handle_close, NULL);
	mlx_mouse_hook(data.win, handle_mouseclick, NULL);
	mlx_loop(data.mlx);
}
