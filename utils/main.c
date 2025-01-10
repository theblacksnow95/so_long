/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:53:00 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/09 15:38:42 by emurillo         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game	game;
	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		format_check(argv[1]);
		map_validation(game.map, &game);
		init_game(game, argv[1]);
	}
	else
	{
		return (ft_printf("Incorrect arguments given.\n"));
	}
	return (0);
}
