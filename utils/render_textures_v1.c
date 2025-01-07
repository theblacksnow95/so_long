/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures_v1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:23:33 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/07 15:30:01 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->ptr, game->win, \
	image, x * 60, y * 60);
}

void	draw_exit(t_game *game, int x, int y)
{
	img_draw(game, game->img_exit, x, y);
}

void	draw_player(t_game *game, void *image, int x, int y)
{
	img_draw(game, image, x, y);
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
			img_draw(game, game->img_floor, x, y);
			if (map[y][x] == '1')
				img_draw(game, game->img_walls, x, y);
			if (map[y][x] == '0')
				img_draw(game, game->img_floor, x, y);
			if (map[y][x] == 'C')
				img_draw(game, game->img_collect, x, y);
			if (map[y][x] == 'E')
				img_draw(game, game->img_exit, x, y);
			if (map[y][x] == 'P')
				draw_player(game, game->img_player, x, y);
			x++;
		}
		y++;
	}
}

void	render_game(t_game *game)
{
	mlx_put_image_to_window(game->ptr, game->win, game->stat_image, 0, 0);
}
