#include "game.h"
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	on_destroy(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);

	int	i = 0;

	mlx_destroy_image(game->mlx_ptr, game->perso.img_ptr[0]);
	mlx_destroy_image(game->mlx_ptr, game->perso.img_ptr[1]);
	mlx_destroy_image(game->mlx_ptr, game->perso.img_ptr[2]);
	mlx_destroy_image(game->mlx_ptr, game->perso.img_ptr[3]);
	mlx_destroy_image(game->mlx_ptr, game->perso.img_ptr[4]);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	//mlx_destroy_window(game->mlx_ptr, game->debugwin);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
//	free(game->perso.img_ptr);
	exit(0);
	return (0);
}
