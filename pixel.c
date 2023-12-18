#include "game.h"
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

void	put_pixel(t_sand *sand, int x, int y, int color)
{
	int	offset;

	offset = (sand->line_len * y) + (x * (sand->bits_per_pixel / 8));

	*((unsigned int *)(offset + sand->img_pixels_ptr)) = color;
	printf("fin de put_pixel\n");
}

void	get_sand(t_sand *sand, t_game *game)
{

	game->sand.img_ptr = mlx_new_image(game->mlx_ptr, 800, 800);
	game->sand.img_pixels_ptr = mlx_get_data_addr(game->sand.img_ptr, &game->sand.bits_per_pixel, &game->sand.line_len, &game->sand.endian);
	int x = 400;
	int y = 400;
	while (y < 450)
	{	
		put_pixel(&game->sand, y, x, 0xff);
		while (x++ < 450)
		{
			
			put_pixel(&game->sand, y, x, 0xffffff);
		}
		printf("%d", x);
		y++;
	}


	printf("fin de get_sand");
}

void	animation_pixel(t_sand *sand, t_game *game)
{
	sand->x = 600 / 2;
	sand->y = 400 / 2;
	printf("avant la boucle");
	//put_pixel(sand, game);
	while (sand->y < 400)
	{
	///	printf("dans la boucle");
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		sand->y += 1;
		//put_pixel(sand, game);
	}
}
