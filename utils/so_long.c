/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:53:00 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/05 15:35:44 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_exists(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n Map does not exist: %s\n", map_name);
		exit(1);
	}
	close(fd);
	return (0);
}

int	format_check(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 10)
	{
		ft_printf("Error\n Map name is too short or incorrect.\n");
		exit(0);
	}
	map_name = map_name + (ft_strlen(map_name) - 4);
	if (map_name[len - 1] == '/')
	{
		ft_printf("Error\n Cannot use directories.\n");
		exit(0);
	}
	if (ft_strncmp(map_name, ".ber", 4))
	{
		ft_printf("Error\n Map extension is incorrect: ('.ber').\n");
		exit(0);
	}
	return (0);
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
	if (argc == 2 && !format_check(argv[1]) && !check_map_exists(argv[1]))
	{
		game.map = read_map(argv[1]);
		locate_player(&game);
		map_validation(game.map, &game);
		init_game(game, argv[1]);
	}
	else
	{
		return (ft_printf("Error\n Incorrect arguments given.\n"));
		return (0);
	}
	return (0);
}
