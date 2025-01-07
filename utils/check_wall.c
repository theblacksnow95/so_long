/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:59:16 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/07 16:37:01 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_walled(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[1][x])
	{
		if (game->map[1][x] != '1')
		{
			ft_printf("Incorrect map, not walled.\n");
			return (1);
		}
		x++;
	}
	x = 0;
	while (game->map[y][0])
	{
		if (game->map[y][0] != '1');

			return (1);

	}

}
