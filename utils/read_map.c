/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:41:10 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/17 12:02:18 by emurillo         ###   ########.fr       */
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
		return (NULL);
	map_str = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		buf = map_str;
		map_str = ft_strjoin(map_str, line);
		free(line);
		free(buf);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}
