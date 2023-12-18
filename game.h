#ifndef GAME_H
# define GAME_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_sprite
{
	void	*img_ptr;
	struct s_sprite    	*next;
}	s_sprite;

typedef struct s_sand
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int	bits_per_pixel;
	int	endian;
	int	line_len;
	int	x;
	int	y;

}	t_sand;

typedef struct s_perso
{
	void	*img_ptr[5];
	int	x;
	int	y;
	int	move;
	int	key;
	int	frame;
	char 	**sprite_paths;
	s_sprite	*sprite;
}	t_perso;

typedef struct s_map
{
	void	*img_ptr;
	int	x;
	int	y;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*debugwin;
	void	*win_ptr;
	void	*textures;
	int	width;
	int	height;
	int	frame;
	t_perso	perso;
	t_sand	sand;
	t_map	map;
}	t_game;


int	mouvement(t_game *game);
int	on_keypress(int keysim, t_game *game);
int	on_destroy(t_game *game);
void	put_pixel(t_sand *sand, int x, int y, int color);
void	animation_pixel(t_sand *sand, t_game *game);
void	get_sand(t_sand *sand, t_game *game);
void	persomouv(t_perso *perso, t_game *game, char *path);
int		animation_perso(t_game *game);
int 	ismove(int keysym, t_game *game);
int		mouvement(t_game *game);
int		stopmove(int keysim, t_game *game);
int	ft_update (t_game *game);
void	init_perso(t_game *game);


#endif
