/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:41:10 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/05 15:45:18 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_read(char *map_str, char *line, char *buf)
{
	ft_printf("Error\n Map not valid.\n");
	free(map_str);
	free(line);
	free(buf);
	exit(0);
	return (0);
}

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
		if (line[0] == '\n')
			close_read(map_str, line, buf);
		buf = map_str;
		map_str = ft_strjoin(buf, line);
		free(line);
		free(buf);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}
