#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <libft.h>
# include <mlx.h>

# define WIN_W 800
# define WIN_H 640

typedef struct s_game
{
	void	*ptr;
	void	*win;
	char	**map;
	void	*img_floor;
	void	*img_walls;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		x_player;
	int		y_plater;
	int		moves;
	int		exit;
}			t_game;

# define  ESC_KEY 65307

# define Q_KEY 113
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define W_KEY 119

# define LEFT_ARROWKEY 65361
# define RIGHT_ARROWKEY 65363
# define DOWN_ARROWKEY 65364
# define UP_ARROWKEY 65362

char	**read_map(const char *map_filepath);
void	preload_textures(t_game *game);
int		init_game(t_game game, char *map);
void	render_map(char **map, t_game *game);

#endif
