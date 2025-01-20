/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:18:56 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/20 11:13:57 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_moves(t_game *game)
{
	if (game->map[game->y_player - 1][game->x_player] == 'E' \
		&& game->exit == 1)
	{
		ft_printf("Money first!.\n");
		ft_printf("You have %d left.\n", game->n_collect);
		return (0);
	}
	if (game->map[game->y_player - 1][game->x_player] != '1')
	{
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		check_moves(game, game->y_player - 1, game->x_player);
		game->y_player--;
		game->moves++;
		ft_printf("Moves: [%d].\n", game->moves);
	}
	return (0);
}

int	down_moves(t_game *game)
{
	if (game->map[game->y_player + 1][game->x_player] == 'E' \
		&& game->exit == 1)
	{
		ft_printf("Money first!.\n");
		ft_printf("You have %d left.\n", game->n_collect);
		return (0);
	}
	if (game->map[game->y_player + 1][game->x_player] != '1')
	{
		check_moves(game, game->y_player + 1, game->x_player);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		game->y_player++;
		game->moves++;
		ft_printf("Moves: [%d].\n", game->moves);
	}
	return (0);
}

int	left_moves(t_game *game)
{
	if (game->map[game->y_player][game->x_player - 1] == 'E' \
		&& game->exit == 1)
	{
		ft_printf("Money first!.\n");
		ft_printf("You have %d left.\n", game->n_collect);
		return (0);
	}
	if (game->map[game->y_player][game->x_player - 1] != '1')
	{
		check_moves(game, game->y_player, game->x_player - 1);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
		game->x_player--;
		game->moves++;
		ft_printf("Moves: [%d].\n", game->moves);
	}
	return (0);
}

int	right_moves(t_game *game)
{
	if (game->map[game->y_player][game->x_player + 1] == 'E' \
		&& game->exit == 1)
	{
		ft_printf("Money first!.\n");
		ft_printf("You have %d left.\n", game->n_collect);
		return (0);
	}
	if (game->map[game->y_player][game->x_player + 1] != '1')
	{
		check_moves(game, game->y_player, game->x_player + 1);
		img_draw(game, game->img_floor, game->x_player, game->y_player);
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
		up_moves(game);
		return (0);
	}
	if (keycode == S_KEY || keycode == DOWN_ARROWKEY)
	{
		down_moves(game);
		return (0);
	}
	if (keycode == A_KEY || keycode == LEFT_ARROWKEY)
	{
		left_moves(game);
		return (0);
	}
	if (keycode == D_KEY || keycode == RIGHT_ARROWKEY)
	{
		right_moves(game);
		return (0);
	}
	return (0);
}
