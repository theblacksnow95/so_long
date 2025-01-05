/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:54:43 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/05 17:01:59 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render_frame(t_game *game)
{
	render_map(game->map, game);
	return (0);
}

static void	window_size(t_game *game)
{
	int i;

	game->map_w = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->map_h = i * 32;

}

int	init_game(t_game game, char *map)
{
	game.ptr = mlx_init();
	if (!game.ptr)
	{
		ft_printf("error inizializing mlx.\n");
		return (1);
	}
	window_size(&game);
	game.win = mlx_new_window(game.ptr, game.map_w, game.map_h, "2D game");
	if (!game.win)
	{
		ft_printf("error creating window.\n");
		return (1);
	}
	game.map = read_map(map);
	if (!map)
	{
		ft_printf("error map path.\n");
		return (1);
	}
	preload_textures(&game);
	mlx_loop_hook(game.ptr, render_frame, &game);
	mlx_loop(game.ptr);
	return (0);
}
