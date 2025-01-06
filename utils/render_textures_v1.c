/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures_v1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:23:33 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/06 16:25:24 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->ptr, game->stat_image, \
	image, x * 32, y * 32);
}

void	draw_exit(t_game *game, int x, int y)
{
	img_draw(game, game->img_exit, x, y);
}

void	render_map(char **map, t_game *game)
{
	int		x;
	int		y;

	game->stat_image = mlx_new_image(game->ptr, game->map_w, game->map_w);
	if (!game->stat_image)
	{
		ft_printf("Error creating static image.\n");
		exit(1);
	}
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
			if (map[y][x] == 'C')
				img_draw(game, game->img_collect, x, y);
			if (map[y][x] == 'E')
				img_draw(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
}

void	render_game(t_game *game)
{
	mlx_put_image_to_window(game->ptr, game->win, game->stat_image, 0, 0);
}
