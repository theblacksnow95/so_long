/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:49:32 by emurillo          #+#    #+#             */
/*   Updated: 2024/12/16 17:50:14 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 640


typedef struct s_game
{
	void	*mlx_ptr;
	void	*win;
	void	*wall;
	void	*background;
	char	*bg_addr;
	int		bg_bpp;
	int		bg_line_length;
	int		bg_endian;
	void	*image;
	int		img_width;
	int		img_height;
	char	**map;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;

} 			t_game;

void	copy_background_to_buffer(t_game *game)
{
	int			x;
	int			y;
	char		*dst;
	char		*src;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			dst = game->addr +(y *game->line_length + x * (game->bpp / 8));
			src = game->bg_addr + ((y % game->img_height) * \
			game->bg_line_length + (x % game->img_width) * (game->bg_bpp / 8));
			*(unsigned int *)dst = *(unsigned int *)src;
			x++;
		}
		y++;
	}

}

int	render_background(t_game *game)
{
	copy_background_to_buffer(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win, game->image, 0, 0);
	return (0);
}

int	main(void)
{
	t_game game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
	{
		perror("Error initializating.\n");
		return (0);
	}
	game.win = mlx_new_window(game.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "2D game");
	if (!game.win)
	{
		ft_printf("Error creating window.\n");
		return (0);
	}
	game.image = mlx_new_image(game.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!game.image)
	{
		perror("Error creating image.\n");
		return (0);
	}
	game.addr = mlx_get_data_addr(game.image, &game.bpp, &game.line_length, &game.endian);
	game.background = mlx_xpm_file_to_image(game.mlx_ptr, "../../images/cover/TX Tileset Grass_resized.xpm", &game.img_width, &game.img_height);
	if (!game.background)
	{
		perror("Error loading xpm file.\n");
		return (0);
	}
	game.bg_addr = mlx_get_data_addr(game.background, &game.bg_bpp, &game.bg_line_length, &game.bg_endian);
	mlx_loop_hook(game.mlx_ptr, render_background, &game);
	mlx_loop(game.mlx_ptr);
}
