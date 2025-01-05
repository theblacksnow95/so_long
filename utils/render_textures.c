/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:23:33 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/05 17:22:46 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->ptr, game->win,\
	 image, x * 32, y * 32);
}
void draw_player(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_plater = y;
	img_draw(game, image, x, y);
}

void draw_exit(t_game *game, int x, int y)
{
	img_draw(game, game->img_exit, x, y);
}

void	render_map(char **map, t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				img_draw(game, game->img_walls, x, y);
			if (map[y][x] == '0')
				img_draw(game, game->img_floor, x, y);
			if (map[y][x] == 'P')
				draw_player(game, game->img_player, x, y);
			if (map[y][x] == 'C')
				img_draw(game, game->img_collect, x, y);
			if (map[y][x] == 'E')
				draw_exit(game, x, y);
			x++;
		}
		y++;
	}
}

void	preload_textures(t_game *game)
{
	game->img_walls = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/TX-Tileset-Wall_resized.xpm", &game->img_w, \
	&game->img_h);
	game->img_floor = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/TX Tileset Grass_resized.xpm", &game->img_w, \
	&game->img_h);
	game->img_collect = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/coin_01.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/characters.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/things.xpm", &game->img_w, &game->img_h);
	if (!game->img_walls || !game->img_floor || !game->img_exit)
	{
		ft_printf("Error loading textures floor, exit, wall.\n");
		exit(1);
	}
	if (!game->img_collect || !game->img_player)
	{
		ft_printf("Error loading textures.\n");
		exit(1);
	}
}
