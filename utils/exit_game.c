/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:15:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/06 16:05:20 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_textures(t_game *game)
{
	if (game->img_collect || game->img_exit || game->img_floor \
	|| game->img_player || game->img_walls)
	{
		free(game->img_collect);
		free(game->img_exit);
		free(game->img_floor);
		free(game->img_player);
		free(game->img_walls);
	}
	return (0);
}

int	close_window(t_game *game)
{
	if (game->win)
	{
		mlx_clear_window(game->ptr, game->win);
		free_textures(game);
		mlx_destroy_window(game->ptr, game->win);
		ft_printf("Closing window...\n");
	}
	if (game->ptr)
		free(game->ptr);
	exit(0);
	return (0);
}

int	close_key(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		close_window(game);
	}
	return (0);
}
