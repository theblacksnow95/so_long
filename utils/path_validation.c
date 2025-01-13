/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:54:08 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/13 16:38:08 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	int		i;
	char	**map_copy;

	i = 0;
	while (map[i])
		i++;
	map_copy = malloc((i + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	flood(char **map, int y, int x, int *coins, int *exit_reachable)
{
	if (y < 0 || x < 0 || !map[y] || map[y][x] == '\0' || map[y][x] == '1')
		return (0);
	if (map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'C')
		(*coins)++;
	if (map[y][x] == 'E')
		*exit_reachable = 1;
	map[y][x] = 'V';
	if (flood(map, y - 1, x, coins, exit_reachable))
		return (1);
	if (flood(map, y + 1, x, coins, exit_reachable))
		return (1);
	if (flood(map, y, x - 1, coins, exit_reachable))
		return (1);
	if (flood(map, y, x + 1, coins, exit_reachable))
		return (1);
	return (*exit_reachable);
}

int	path_validation(char **map, int y, int x, int coins)
{
	int		i;
	int		coll;
	int		exit_reachable;
	char	**map_copy;

	i = 0;
	coll = 0;
	exit_reachable = 0;
	map_copy = copy_map(map);
	if (!map_copy)
		exit(1);
	flood(map_copy, y, x, &coll, &exit_reachable);
	while (map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	if (coins != coll)
		return (0);
	if (!exit_reachable)
		return (0);
	free(map_copy);
	return (1);
}
