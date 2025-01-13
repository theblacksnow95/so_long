/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:18:56 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/13 11:06:07 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_moves(int keycode, t_game *game)
{
	if (game->map[game->y_player - 1][game->x_player] == 'E' \
		&& game->exit == 1)
		return (0);
	if (game->map[game->y_player - 1][game->x_player] != '1')
	{
		ft_printf("Checking position above: y = %d, x = %d\n", \
					game->y_player - 1, game->x_player);
		ft_printf("key pressed: %d\n", keycode);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		check_moves(game, game->y_player - 1, game->x_player);
		game->y_player--;
		game->moves++;
		ft_printf("Moves: [%d].\n", game->moves);
	}
	return (0);
}

int	down_moves(int keycode, t_game *game)
{
	if (game->map[game->y_player + 1][game->x_player] == 'E' \
		&& game->exit == 1)
		return (0);
	if (game->map[game->y_player + 1][game->x_player] != '1')
	{
		ft_printf("Checking position above: y = %d, x = %d\n", \
				game->y_player + 1, game->x_player);
		check_moves(game, game->y_player + 1, game->x_player);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		ft_printf("key pressed: %d\n", keycode);
		game->y_player++;
		game->moves++;
		ft_printf("Moves: [%d].\n", game->moves);
	}
	return (0);
}

int	left_moves(int keycode, t_game *game)
{
	if (game->map[game->y_player][game->x_player - 1] == 'E' \
		&& game->exit == 1)
		return (0);
	if (game->map[game->y_player][game->x_player - 1] != '1')
	{
		check_moves(game, game->y_player, game->x_player - 1);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		ft_printf("key pressed: %d\n", keycode);
		game->x_player--;
		game->moves++;
		ft_printf("Moves: [%d].\n", game->moves);
	}
	return (0);
}

int	right_moves(int keycode, t_game *game)
{
	if (game->map[game->y_player][game->x_player + 1] == 'E' \
		&& game->exit == 1)
		return (0);
	if (game->map[game->y_player][game->x_player + 1] != '1')
	{
		ft_printf("Checking position above: y = %d, x = %d\n", \
				game->y_player + 1, game->x_player);
		check_moves(game, game->y_player, game->x_player + 1);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		ft_printf("key pressed: %d\n", keycode);
		game->x_player++;
		game->moves++;
		ft_printf("Moves: [%d].\n", game->moves);
	}
	return (0);
}

int	moves(int keycode, t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'P')
	{
		game->map[game->y_player][game->x_player] = '0';
	}
	if ((keycode == W_KEY && game->y_player > 0) || keycode == UP_ARROWKEY)
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
