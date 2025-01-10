/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:18:56 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/10 21:23:48 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	locate_player(t_game *game)
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
	if (game->map[game->y_player - 1][game->x_player] != '1')
	{
/* 		if (game->y_player > 0)
			ft_printf("Checking position above: y = %d, x = %d\n", \
			game->y_player - 1, game->x_player);
		if (game->map[game->y_player - 1][game->x_player] == '0')
		{
			img_draw(game, game->img_floor, game->x_player, game->y_player);
			game->y_player--;
			img_draw(game, game->img_player, game->x_player, game->y_player);
			ft_printf("key pressed: %d\n", keycode);
		} */
		ft_printf("Checking position above: y = %d, x = %d\n", \
					game->y_player - 1, game->x_player);
		ft_printf("key pressed: %d\n", keycode);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		check_moves(game, game->y_player - 1, game->x_player);
		game->y_player--;
	}
	return (0);
}

int	down_moves(int keycode, t_game *game)
{
	if (game->map[game->y_player + 1][game->x_player] != '1')
	{
		ft_printf("Checking position above: y = %d, x = %d\n", \
				game->y_player + 1, game->x_player);
		check_moves(game, game->y_player + 1, game->x_player);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		ft_printf("key pressed: %d\n", keycode);
		game->y_player++;
	}
	return (0);
}

int	left_moves(int keycode, t_game *game)
{
	if (game->map[game->y_player][game->x_player - 1] != '1')
	{
		check_moves(game, game->y_player, game->x_player - 1);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		ft_printf("key pressed: %d\n", keycode);
		game->x_player--;
	}
	return (0);
}

int	right_moves(int keycode, t_game *game)
{
	if (game->map[game->y_player][game->x_player + 1] != '1')
	{
		ft_printf("Checking position above: y = %d, x = %d\n", \
				game->y_player + 1, game->x_player);
		check_moves(game, game->y_player, game->x_player + 1);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		ft_printf("key pressed: %d\n", keycode);
		game->x_player++;
	}
	return (0);
}

int	moves(int keycode, t_game *game)
{
	game->map[game->y_player][game->x_player] = '0';
	if ((keycode == W_KEY && game->y_player > 0 ) || keycode == UP_ARROWKEY)
	{
		up_moves(keycode, game);
		return (0);
	}
	if (keycode == S_KEY || keycode == DOWN_ARROWKEY)
	{
		down_moves(keycode, game);
		return (0);
	}
	if (keycode == A_KEY || keycode == LEFT_ARROWKEY)
	{
		left_moves(keycode, game);
		return (0);
	}
	if (keycode == D_KEY || keycode == RIGHT_ARROWKEY)
	{
		right_moves(keycode, game);
		return (0);
	}
	return (0);
}
