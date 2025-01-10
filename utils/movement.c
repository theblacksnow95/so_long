/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:18:56 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/10 11:49:16 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	locate_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->y_player = y;
				game->x_player = x;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	up_moves(int keycode, t_game *game)
{
	if (game->y_player > 0)
	{
		ft_printf("locating player.\n");
		locate_player(game);
		ft_printf("Current player position: y = %d, x = %d\n", \
		game->y_player, game->x_player);
		if (game->y_player > 0)
			ft_printf("Checking position above: y = %d, x = %d\n", \
			game->y_player - 1, game->x_player);
		if (game->map[game->y_player - 1][game->x_player] == '0')
		{
			img_draw(game, game->img_floor, game->x_player, game->y_player);
			game->map[game->y_player][game->x_player] = '0';
			game->y_player--;
			img_draw(game, game->img_player, game->x_player, game->y_player);
			game->map[game->y_player][game->x_player] = 'P';
			ft_printf("key pressed: %d", keycode);
		}
	}
	return (0);
}

int	moves(int keycode, t_game *game)
{

	if ((keycode == W_KEY && game->y_player > 0 ) || keycode == UP_ARROWKEY)
	{
		up_moves(keycode, game);
		return (0);
	}
	return (0);
}
