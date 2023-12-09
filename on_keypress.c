#include "game.h"
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

int	on_keypress(int keysym, t_game *game)
{
	(void)game;
	printf("pressed key: %d\n", keysym);
	if (keysym == 65307)
		on_destroy(game);
	return (0);
}
