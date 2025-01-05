/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:41:10 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/05 15:51:51 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(const char *map_filepath)
{
	char	**map;
	char	*line;
	char	*map_str;
	char	*buf;
	int		fd;

	fd = open(map_filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error accessing the file path: %s", map_filepath);
		return (0);
	}
	map_str = ft_strdup("");
	while ((line = get_next_line(fd)) != NULL)
	{
		buf = map_str;
		map_str =ft_strjoin(map_str, line);
		free(buf);
		free(line);
	}
	close(fd);
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}

