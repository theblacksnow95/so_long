/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:59:16 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:03 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	int	rows;
	int	cols;
	int	i;

	if (!map || !map[0])
		return (0);
	cols = ft_strlen(map[0]);
	i = 0;
	rows = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != (size_t)cols)
		{
			return (0);
		}
		rows++;
		i++;
	}
	if (rows < 2 || cols < 2)
		return (0);
	return (1);
}

int	is_walled(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
		y++;
	while (map[0][x] != '\0' && map[y - 1][x] != '\0')
	{
		if (map[0][x] != '1' || map[y - 1][x] != '1')
			return (1);
		x++;
	}
	y = 0;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	valid_components(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
				game->n_player++;
			else if (game->map[y][x] == 'C')
				game->n_collect++;
			else if (game->map[y][x] == 'E')
				game->exit++;
			x++;
		}
		x = 0;
		y++;
	}
	if (game->exit != 1 || game->n_player != 1 || game->n_collect == 0)
		return (0);
	return (1);
}

int	is_chars(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != 'P' && \
				map[y][x] != 'E' && map[y][x] != '0')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	map_validation(char **map, t_game *game)
{
	game->n_player = 0;
	game->n_collect = 0;
	game->exit = 0;
	game->moves = 0;
	if (is_walled(map) || !valid_components(game) || \
	is_chars(map) || !is_rectangle(map))
	{
		ft_printf("Error\n Map not valid.\n");
		free_map(game->map);
		close_window(game);
	}
	if (!path_validation(map, game->y_player, game->x_player, game->n_collect))
	{
		ft_printf("Error\n No valid path in map.\n");
		free_map(game->map);
		close_window(game);
	}
	return (0);
}
