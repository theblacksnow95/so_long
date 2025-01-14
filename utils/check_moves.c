/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:32:21 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/14 16:41:24 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_floor(t_game *game, int y_player, int x_player)
{
	if (game->map[y_player][x_player] == '0')
	{
		img_draw(game, game->img_player, x_player, y_player);
	}
	return (0);
}

static int	check_exit(t_game *game, int y_player, int x_player)
{
	if (game->map[y_player][x_player] == 'E' \
	&& game->n_collect == 0 && game->exit == 0)
	{
		img_draw(game, game->img_player, x_player, y_player);
		ft_printf("You won, congrats, you are a functional human being!!.\n");
		close_window(game);
	}
	if (game->map[y_player][x_player] == 'E' \
	&& game->n_collect != 0 && game->exit != 0)
	{
		ft_printf("Money first!.\n");
		ft_printf("You have %d left.\n", game->n_collect);
		return (1);
	}
	return (0);
}

static int	check_collectible(t_game *game, int y_player, int x_player)
{
	ft_printf("Coins left: %d\n", game->n_collect);
	if (game->map[y_player][x_player] == 'C' && \
	game->n_collect != 0)
	{
		img_draw(game, game->img_player, x_player, y_player);
		game->map[y_player][x_player] = '0';
		game->n_collect--;
	}
	return (0);
}

int	check_moves(t_game *game, int y_player, int x_player)
{
	if (game->map[y_player][x_player] == '1')
		return (1);
	if (game->n_collect == 0)
		game->exit = 0;
	check_collectible(game, y_player, x_player);
	check_floor(game, y_player, x_player);
	check_exit(game, y_player, x_player);
	return (0);
}
