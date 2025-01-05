/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:32:30 by emurillo          #+#    #+#             */
/*   Updated: 2024/12/17 14:20:57 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#define MAP_WIDTH 24
#define MAP_HEIGHT 8


typedef struct s_textures
{
	void	*wall;
	void	*floor;
	int		img_width;
	int		img_height;
}			t_textures;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win;
	char		**map;
	t_textures	textures;
}			t_data;

char	**read_map(const char *filename)
{
	int		fd;
	char	**map;
	int		i;
	ssize_t	bytes_read;

	i = 0;
	fd = open(filename,  O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file.\n");
		return (NULL);
	}
	map = malloc(sizeof(char *) *(MAP_HEIGHT + 1));
	if (!map)
		return (NULL);
	while (i < MAP_HEIGHT)
	{
		map[i] = malloc(MAP_WIDTH + 2);
		if (!map[i])
		{
			perror("Error allocating memory");
			while (--i)
				free(map[i]);
			free(map);
			close (fd);
			return(NULL);
		}
		bytes_read = read(fd, map[i], MAP_WIDTH + 1);
		if (bytes_read < 0)
		{
			perror("Error reading file.\n");
			ft_printf("Failed to read file.\n");
			return (NULL);
		}
		if (bytes_read != MAP_WIDTH + 1 || map[i][MAP_WIDTH] != '\n')
		{
			perror("Error reading file.\n");
			while (i >= 0)
				free(map[i--]);
			free(map);
			close (fd);
			return (NULL);
		}
		map[i][MAP_WIDTH] = '\0';
		i++;
	}
	map[MAP_HEIGHT] = NULL;
	close(fd);
	return (map);
}

void	preload_textures(void *mlx, t_textures *textures)
{
	textures->wall = mlx_xpm_file_to_image(mlx, "../../images/cover/TX-Tileset-Wall_resized.xpm", &textures->img_width, &textures->img_height);
	textures->floor = mlx_xpm_file_to_image(mlx, "../../images/cover/TX Tileset Grass_resized.xpm", &textures->img_width, &textures->img_height);
	if (!textures->wall || !textures->floor)
	{
		ft_printf("Error loading textures.\n");
		exit(1);
	}
}

void	render_map(void * mlx, void *win, char **map, t_textures *textures)
{
	int		x;
	int		y;
	int		tile_size;
	int		tile_width;
	int		tile_height;
	void	*img_todraw;
	int		offset;

	tile_width = WIN_WIDTH / MAP_WIDTH;
	tile_height = WIN_HEIGHT / MAP_HEIGHT;
	if (tile_width < tile_height)
		tile_size = tile_width;
	else
		tile_size = tile_height;
	tile_size = tile_width;
	offset = (WIN_HEIGHT - (tile_size * MAP_HEIGHT)) / 2;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			img_todraw = NULL;
			if (map[y][x] == '1')
				img_todraw = textures->wall;
			if (map[y][x] == '0')
				img_todraw = textures->floor;
			if (img_todraw)
				mlx_put_image_to_window(mlx, win, img_todraw, x * tile_size, y * tile_size + offset);
			x++;
		}
		y++;
	}
}

int	render_frame(t_data *data)
{
	render_map(data->mlx_ptr, data->win, data->map, &data->textures);
	return (0);
}

int	handle_keys(int keycode)
{
	static int	count;

	if (keycode >= 65361 && keycode <= 65364)
	{
		count += 1;
		printf("# Moves: %d\n", count);
	}
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
	{
		count += 1;
		printf("# Moves: %d\n", count);
	}
	else if (keycode == 65307)
	{
		ft_printf("ESC key pressed, exiting...\n");
		exit(0);
		return (0);
	}
	return (count);
}

int	handle_close(void *param)
{
	(void)param;
	ft_printf("Window closed. Exiting...\n");
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	game.win = mlx_new_window(game.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "2D Game");
	if (!game.win)
		return (1);
	game.map = read_map("../../maps/map_1.ber");
	if (!game.map)
	{
		ft_printf("Error loading the map.\n");
		return (1);
	}
	preload_textures(game.mlx_ptr, &game.textures);
	mlx_hook(game.win, 17, 0L, handle_close, &game);
	mlx_hook(game.win, 3, 1L << 1, handle_keys, NULL);
	mlx_loop_hook(game.mlx_ptr, render_frame, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
