#include "game.h"
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

int	on_keypress(int keysym, t_game *game)
{
	(void)game;
	char	*path = "./assets/perso.xpm";

	printf("pressed key: %d\n", keysym);
	if (keysym == 65307)
		on_destroy(game);

	if (keysym == 65363)//droite
	{
		game->perso.x += 10;
		persomouv(&game->perso, game, path);
	}
	if (keysym == 65361)//gauche
        {
                game->perso.x -= 3;
                persomouv(&game->perso, game, path);
        }
	if (keysym == 65362)//haut
        {
                game->perso.y -= 10;
                persomouv(&game->perso, game, path);
        }
	if (keysym == 65364)//bas
        {
                game->perso.y += 10;
		persomouv(&game->perso, game, path);
        }



	return (0);
}
