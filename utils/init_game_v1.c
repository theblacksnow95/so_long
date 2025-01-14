/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:54:43 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/14 15:24:08 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	preload_textures(t_game *game)
{
	game->img_walls = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/TX Tileset Wall_v1.xpm", &game->img_w, \
	&game->img_h);
	game->img_floor = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/TX Tileset Grass_v1.xpm", &game->img_w, \
	&game->img_h);
	game->img_collect = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/coin_01.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/character_v2.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->ptr, \
	"images/cover/TX Struct_v1.xpm", &game->img_w, &game->img_h);
	if (!game->img_walls || !game->img_floor || !game->img_exit)
	{
		ft_printf("Error loading textures floor, exit, wall.\n");
		exit(1);
	}
	if (!game->img_collect || !game->img_player)
	{
		ft_printf("Error loading textures.\n");
		exit(1);
	}
}

static int	render_frame(t_game *game)
{
	render_map(game->map, game);
	return (0);
}

static void	window_size(t_game *game)
{
	int	i;

	if (!game->map || !game->map[0])
	{
		ft_printf("Error: Map is invalid or empty.\n");
		exit(1);
	}
	game->map_w = ft_strlen(game->map[0]) * 60;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->map_h = i * 60;
}

int	init_game(t_game game, char *map)
{
	game.ptr = mlx_init();
	if (!game.ptr)
	{
		ft_printf("error inizializing ml11x.\n");
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
	preload_textures(&game);
	if (!map)
		return (1);
	mlx_hook(game.win, 2, 1L >> 0, moves, &game);
	mlx_key_hook(game.win, close_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	render_frame(&game);
	mlx_loop(game.ptr);
	return (0);
}
