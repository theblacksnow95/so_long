/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:53:00 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/17 11:55:59 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	format_check(char *map_name)
{
	map_name = map_name + (ft_strlen(map_name) - 4);
	if (ft_strncmp(map_name, ".ber", 4))
	{
		ft_printf("Map extension is incorrect, correct one is '.ber'.\n");
		exit(1);
	}
}

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

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		format_check(argv[1]);
		locate_player(&game);
		map_validation(game.map, &game);
		init_game(game, argv[1]);
	}
	else
	{
		return (ft_printf("Incorrect arguments given.\n"));
		return (0);
	}
	return (0);
}
