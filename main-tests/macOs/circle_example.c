/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_example.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:51:53 by emurillo          #+#    #+#             */
/*   Updated: 2024/12/09 14:15:32 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define CIRCLE_RADIUS 30


typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}			t_vars;

void	draw_circle(t_vars *data)
{
	int	x;
	int	y;
	int	color;
	int	dx;
	int	dy;

	color = 0x00FFFFFF;
	y = data->y - CIRCLE_RADIUS;
	while (y <= data->y + CIRCLE_RADIUS)
	{
		x = data->x - CIRCLE_RADIUS;
		while (x <= data->x + CIRCLE_RADIUS)
		{
			dx = x - data->x;
			dy = y - data->y;
			if ((dx * dx + dy * dy) <= (CIRCLE_RADIUS * CIRCLE_RADIUS))
				mlx_pixel_put(data->mlx, data->win, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_frame(t_vars *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_circle(data);
	return (0);
}


int	handle_keypress(int keycode, t_vars *data)
{
	if (keycode == 0 || keycode == 123)
		data->x -= 10;
	else if (keycode == 1 || keycode == 125)
	data->y += 10;
	else if (keycode == 2 || keycode == 124)
		data->x += 10;
	else if (keycode == 13 || keycode == 126)
	data->y -= 10;
	else if (keycode == 53)
	{
		printf("ESC key pressed, exiting...\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	close(void *param)
{
	(void)param;
	printf("Window closed. Exiting...\n");
	exit(0);
	return (0);
}

int	main(void)
{
	t_vars	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Circle example");
	data.x = WIN_WIDTH / 2;
	data.y = WIN_HEIGHT / 2;
	mlx_key_hook(data.win, handle_keypress, &data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_hook(data.win, 17, 0L, close, NULL);
	mlx_loop(data.mlx);
}
