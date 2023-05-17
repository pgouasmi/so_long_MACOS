/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:07:55 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/16 19:05:07 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_checker_initialize(t_game *game)
{
	game->map.c_count = 0;
	game->map.e_count = 0;
	game->map.p_count = 0;
	game->img.win_width = 64 * game->map.row;
	game->img.win_height = 64 * game->map.line;
	ft_printf("win_width : %d\n\n", game->img.win_width);

}

void	ft_set_img_path(t_game *game)
{
	game->img.path = "./sprites/";
	game->img.character = "./sprites/character.xpm";
	game->img.wall = "./sprites/obstacle.xpm";
	game->img.floor = "./sprites/grass.xpm";
	game->img.collectible = "./sprites/ring.xpm";
	game->img.exit_closed = "./sprites/closed_door.xpm";
	game->img.exit_open = "./sprites/open_door.xpm";
	game->img.ennemy = "./sprites/ennemy.xpm";
}

void	ft_img_first(t_game *game)
{
	game->img.char_img = mlx_new_image(game->mlx_ptr, 64, 64);
	game->img.wall_img = mlx_new_image(game->mlx_ptr, 64, 64);
	game->img.floor_img = mlx_new_image(game->mlx_ptr, 64, 64);
	game->img.collect_img = mlx_new_image(game->mlx_ptr, 64, 64);
	game->img.cl_exit_img = mlx_new_image(game->mlx_ptr, 64, 64);
	game->img.op_exit_img = mlx_new_image(game->mlx_ptr, 64, 64);
	game->img.ennemy_img = mlx_new_image(game->mlx_ptr, 64, 64);
}

void	ft_set_img_void(t_game *game)
{
	int height, width;

	game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.character, &width, &height);
	game->img.wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.wall, &width, &height);
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.floor, &width, &height);
	game->img.collect_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.collectible, &width, &height);
	game->img.cl_exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.exit_closed, &width, &height);
	game->img.op_exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.exit_open, &width, &height);
	game->img.ennemy_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->img.ennemy, &width, &height);
}

void	ft_set_img(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return(ft_free_struct(game, 3), exit(1));
	ft_set_img_path(game);
	ft_img_first(game);
	ft_set_img_void(game);
}
