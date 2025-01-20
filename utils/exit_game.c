/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:15:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/20 11:38:59 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_textures(t_game *game)
{
	if (game->img_collect || game->img_exit || game->img_floor \
	|| game->img_player || game->img_walls)
	{
		mlx_destroy_image(game->ptr, game->img_collect);
		mlx_destroy_image(game->ptr, game->img_exit);
		mlx_destroy_image(game->ptr, game->img_floor);
		mlx_destroy_image(game->ptr, game->img_player);
		mlx_destroy_image(game->ptr, game->img_walls);
	}
	ft_printf("Freeing textures...\n");
	return (0);
}

int	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
	return (0);
}

int	close_window(t_game *game)
{
	if (game->win)
	{
		mlx_clear_window(game->ptr, game->win);
		free_textures(game);
		mlx_destroy_window(game->ptr, game->win);
		mlx_destroy_display(game->ptr);
		ft_printf("Closing window...\n");
	}
	if (game->ptr)
	{
		free(game->ptr);
		free_map(game->map);
		ft_printf("Freeing mlx and map...\n");
	}
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
