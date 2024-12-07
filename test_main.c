/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:16:16 by emurillo          #+#    #+#             */
/*   Updated: 2024/12/07 14:58:12 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	handle_keypress(int keycode)
{
	printf("key pressed: %d\n", keycode);
	if (keycode == 53)
		exit(0);
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
	printf("Window created");
	img = mlx_xpm_file_to_image(mlx, "images/tests/world_tileset.xpm", \
	&img_width, &img_height);
	if (!img)
		return (printf("error reading img\n"));
	else
		printf("Image loaded");
	mlx_put_image_to_window(mlx, mlx_win, img, 1, 1);
	mlx_key_hook(mlx, handle_keypress, NULL);
	if (!mlx_win)
		return (1);
	mlx_loop(mlx);
}
