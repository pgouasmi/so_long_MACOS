#include "so_long.h"

void	ft_test(t_game *game)
{
	int width, height;

	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 800, "caca");
	// game->img.char_img = mlx_new_image(game->mlx_ptr, 64, 64);
	game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/character.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.char_img, 0, 0);
	game->img.collect_img = mlx_new_image(game->mlx_ptr, 64, 64);
	game->img.collect_img = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/ring.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.collect_img, 64, 0);
	game->img.floor_img = mlx_new_image(game->mlx_ptr, 64, 64);
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/grass.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor_img, 128, 0);
	mlx_loop(game->mlx_ptr);



}