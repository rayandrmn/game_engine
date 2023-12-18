#include "game.h"
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	main(void)
{
	t_game game;
	
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (0);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 800, 800, "game engine");
	if (!game.win_ptr)
		return (free(game.mlx_ptr), 0);

	init_perso(&game);
	mlx_loop_hook(game.mlx_ptr, mouvement, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

