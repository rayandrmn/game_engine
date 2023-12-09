#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures; // MLX image pointers (on the stack)
	int		droite;
	int		gauche;
	int		width;
	int		height;
	int		frame;
}	t_data;

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	changeSprite(t_data *data, int frame)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (frame == 0)
	{
		data->textures = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wizard1.xpm", &data->width, &data->height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures, data->droite, data->gauche);
	}
	else if (frame == 1)
	{
		data->textures = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wizard2.xpm", &data->width, &data->height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures, data->droite, data->gauche);
	}
	else if (frame == 2)
	{
		data->textures = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wizard3.xpm", &data->width, &data->height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures, data->droite, data->gauche);
	}
	else if (frame == 3)
	{
		data->textures = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wizard4.xpm", &data->width, &data->height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures, data->droite, data->gauche);
	}



}
int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("pressed key: %d\n", keysym);
	if (keysym == 65307)
		on_destroy(data);
	if (keysym == 65363) //droite
	{
		data->droite += 5;
		changeSprite(data, data->frame++);
		if (data->frame == 4)
			data->frame = 0;
	}
	return (0);
}

int main(void)
{
	t_data	data;
	
	data.frame = 0;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "ma fenetre");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	data.textures = malloc(sizeof(void) * 5);
	data.textures = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/wizard0.xpm", &data.width, &data.height);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures, data.droite, data.gauche);

	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	mlx_loop(data.mlx_ptr);
	free(data);
	return (0);
}
