#include "game.h"
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <unistd.h>



void	persomouv(t_perso *perso, t_game *game, char *path)
{
	int	height;
	int	width;
	
	
	

//		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		//mlx_destroy_image(game->mlx_ptr, game->perso.img_ptr);
	
		//game->perso.img_ptr[0] = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
		
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->perso.img_ptr[0], game->perso.x, game->perso.y);
}




int	ft_update (t_game *game)
{
	// a static that saves how many frames have passed

	// add a frame and every x frames change the position by 1 pixel
	// so it looks like its animated
		//program->perso.y += 10;
		char *wizard_paths[] = {
        "./assets/wizard0.xpm",
        "./assets/wizard1.xpm",
        "./assets/wizard2.xpm",
        "./assets/wizard3.xpm",
        "./assets/wizard4.xpm"
    };

		
		
		persomouv(&game->perso, game, wizard_paths[game->perso.move]);
		game->perso.move++;
		if (game->perso.move == 5)
			game->perso.move = 0;;
	

	return (0);
}


	void    init_perso(t_game *game)
{
        char *path[] =
        {
        "./assets/wizard0.xpm",
        "./assets/wizard1.xpm",
        "./assets/wizard2.xpm",
        "./assets/wizard3.xpm",
        "./assets/wizard4.xpm"
        };
        int i;
        int     j = 0;
        int     width;
        int     height;
	game->map;
	game->perso.x = 400;
	game->perso.y = 400;
	game->perso.frame = 0;
	game->frame = 0;
        i = 0;;
	game->map.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/1.xpm", &width, &height);
//	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map.img_ptr, 0, 0);
//	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map.img_ptr, 32, 0);

	game->perso.sprite_paths = path;
	game->perso.img_ptr[0] = mlx_xpm_file_to_image(game->mlx_ptr, game->perso.sprite_paths[0], &width, &height);
	game->perso.img_ptr[1] = mlx_xpm_file_to_image(game->mlx_ptr, game->perso.sprite_paths[1], &width, &height);
	game->perso.img_ptr[2] = mlx_xpm_file_to_image(game->mlx_ptr, game->perso.sprite_paths[2], &width, &height);
	game->perso.img_ptr[3] = mlx_xpm_file_to_image(game->mlx_ptr, game->perso.sprite_paths[3], &width, &height);
	game->perso.img_ptr[4] = mlx_xpm_file_to_image(game->mlx_ptr, game->perso.sprite_paths[4], &width, &height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->perso.img_ptr[0], game->perso.x, game->perso.y);



	game->perso.x = 32;
	game->perso.y = 0;
//	game->perso.sprite->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, game->perso.sprite_paths[0], &width, &height);
//	s_sprite *s1;
//	game->perso.sprite->next = s1;



//	s1->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, game->perso.sprite_paths[4], &width, &height);
//	s1->next = NULL;

	


}

int	mouvement(t_game *game)
{
	int	i = game->perso.frame;
	
	if (game->frame == 60)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->map.img_ptr, 0, 0);
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->map.img_ptr, 32, 0);

        	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->perso.img_ptr[i], game->perso.x, game->perso.y);
		game->perso.frame++;
	}
	if (game->perso.frame == 5)
		game->perso.frame = 0;
	game->frame++;
	if (game->frame == 1000)
		game->frame = 0;
}



