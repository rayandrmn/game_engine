#ifndef GAME_H
# define GAME_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures;
	int	width;
	int	height;
}	t_game;

typedef struct s_sand
{
	void	*textures;
	int	x;
	int	y;

}	t_sand;


int	on_keypress(int keysim, t_game *game);
int	on_destroy(t_game *game);
void	put_pixel(t_sand *sand, t_game *game);
#endif
