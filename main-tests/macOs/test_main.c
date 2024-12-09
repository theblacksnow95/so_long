/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:16:16 by emurillo          #+#    #+#             */
/*   Updated: 2024/12/09 13:05:16 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

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


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 800, 600, "Test Window");
	printf("Window created.\n");
	img = mlx_png_file_to_image(mlx, "../../images/tests/world_tileset.png", \
	&img_width, &img_height);
	if (!img)
		return (printf("Error reading img.\n"));
	else
		printf("Image loaded.\n");
	mlx_put_image_to_window(mlx, mlx_win, img, 1, 1);
	mlx_key_hook(mlx_win, handle_keypress, NULL);
	mlx_hook(mlx_win, 17, 0L, handle_close, NULL);
	mlx_mouse_hook(mlx_win, handle_mouseclick, NULL);
	if (!mlx_win)
		return (1);
	mlx_loop(mlx);
}
