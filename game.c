#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "game.h"

int	main(void)
{
	t_game	game;
	t_sand	sand;

	sand.x = 0;
	sand.y = 0;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 600, 400, "sandbox");
	if (!game.win_ptr)
		return (free(game.mlx_ptr), 1);
	
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
	put_pixel(&sand, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
