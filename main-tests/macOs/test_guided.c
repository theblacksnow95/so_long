/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_guided.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:39:53 by emurillo          #+#    #+#             */
/*   Updated: 2024/12/09 13:49:32 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct svars
{
	void	*mlx;
	void	*win;
	double	color_phase;
}				t_vars;

int	get_rainbow_color(double phase)
{
	int	red;
	int	green;
	int	blue;

	phase = fmod(phase, 3.0);

	if (phase < 1.0)
	{
		red = (int)(255 * (1.0 - phase));
		green = (int)(255 * phase);
		blue = 0;
	}
	else if (phase < 2.0)
	{
		red = 0;
		green = (int)(255 * (2.0 - phase));
		blue = (int)(255 * (phase - 1.0));
	}
	else
	{
		red = (int)(255 * (phase - 2.0));
		green = 0;
		blue = (int)(255 * (3.0 - phase));
	}
	return (red << 16 | green << 8 | blue);
}

int	render_frame(t_vars *data)
{
	int	x;
	int	y;
	int	color;

	color = get_rainbow_color(data->color_phase);
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, color);
			x++;
		}
		y++;
	}

	data->color_phase += 0.08;

	return (0);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_close(void *param)
{
	(void)param;
	printf("Window closed. exiting...\n");
	exit(0);
	return (0);
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		printf("ESC pressed, exiting...\n");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	add_shade(double distance, int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (color >> 24) & 0xFF;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (int)(r * (1 - distance));
	g = (int)(g * (1 - distance));
	b = (int)(b * (1 - distance));

	return (t << 24 | r << 16 | g << 8 | b);
}

int	count_moves(int keycode)
{
	static int	count;

	if (keycode >= 123 && keycode <= 126)
	{
		count += 1;
		printf("# Moves: %d\n", count);
	}
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
	{
		count += 1;
		printf("# Moves: %d\n", count);
	}

	return (count);
}


int	main(void)
{
	t_vars	vars;
	int		color;
/* 	int		shaded_color;
	double	distance; */
	int		x;
	int		y;

	color = 0x00ADD8E6;
	x = 0;
	y = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.color_phase = 0.0;
	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_hook(vars.win, 3, 1L << 1, count_moves, NULL);
	mlx_hook(vars.win, 17, 0L, handle_close, NULL);
/* 	while (x < 1920 )
	{
		distance = (double)x /800.0;
		shaded_color = add_shade(distance, color);
		y = 0;
		while (y < 1080)
		{
			mlx_pixel_put(vars.mlx, vars.win, x, y, shaded_color);
			y++;
		}
		x++;
	} */
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
}
