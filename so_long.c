/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:26:58 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/10 12:45:37 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(t_game *game)
{
	game->img.path = "./sprites/";
	game->img.character = ft_strjoin(game->img.path, "character.xpm");
	game->img.wall = ft_strjoin(game->img.path, "obstacle.xpm");
	game->img.floor = ft_strjoin(game->img.path, "grass.xpm");
	game->img.collectible = ft_strjoin(game->img.path, "ring.xpm");
	game->img.exit_closed = ft_strjoin(game->img.path, "closed_door.xpm");
	game->img.exit_open = ft_strjoin(game->img.path, "open_door.xpm");
	game->img.ennemy = ft_strjoin(game->img.path, "ennemy.xpm");
	game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.character, &(game->img.width), &(game->img.height));
	if (game->img.char_img == NULL)
		ft_printf("xpm_file_to_img CACA\n");
	game->img.wall_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.wall, &(game->img.width), &(game->img.height));
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.floor, &(game->img.width), &(game->img.height));
	game->img.collect_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.collectible, &(game->img.width), &(game->img.height));
	game->img.cl_exit_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.exit_closed, &(game->img.width), &(game->img.height));
	game->img.op_exit_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.exit_open, &(game->img.width), &(game->img.height));
	game->img.ennemy_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.ennemy, &(game->img.width), &(game->img.height));

}

void other_render(t_game *game)
{
	int i;
	size_t j;

	i = 0;
	j = 0;
	while (game->map.full_map[j])
	{
		while(j < game->map.line)
		{
			if (game->map.full_map[j][i] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.collect_img, j * 64, i * 64);
			if (game->map.full_map[j][i] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.char_img, j * 64, i * 64);
			if (game->map.full_map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.cl_exit_img, j * 64, i * 64);
			i++;
		}
		i = 0;
		j++;
	}
}

void background_render(t_game *game)
{
	int i;
	size_t j;

	i = 0;
	j = 0;
	(void) game;
	//ft_printf("map[%d] = %s\n", j, game->map.full_map[j]);
	// while (j < game->map.line)
	// {
	// 	while(game->map.full_map[j][i] || game->map.full_map[j][i] != '\n')
	// 	{
	// 		ft_printf("len map[%d] = %d\n", j, ft_strlen((const char *) game->map.full_map[j]));
	// 		if (game->map.full_map[j][i] == '1')
	// 			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.wall_img, j * 64, i * 64);
	// 		ft_printf("img to win ?\n");
	// 		ft_printf("i = %d, j = %d\n", i, j);
	// 		if (game->map.full_map[j][i] == '0')
	// 			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor_img, j * 64, i * 64);
	// 		i++;
	// 	}
	// 	i = 0;
	// 	j++;
	// }
}

int render_next_frame(t_game *game)
{
	background_render(game);
	//other_render(game);
	return (0);
}

int	end(t_game *game)
{
	int		i;

	i = 0;
	if (game->map.full_map != NULL)
	{
		while (game->map.full_map[i] != NULL)
		{
			free(game->map.full_map[i]);
			i++;
		}
		free(game->map.full_map);
		mlx_destroy_image(game->mlx_ptr, game->img.wall_img);
		mlx_destroy_image(game->mlx_ptr, game->img.floor_img);
		mlx_destroy_image(game->mlx_ptr, game->img.collect_img);
		mlx_destroy_image(game->mlx_ptr, game->img.char_img);
		mlx_destroy_image(game->mlx_ptr, game->img.cl_exit_img);
		mlx_destroy_image(game->mlx_ptr, game->img.op_exit_img);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	free(game->mlx_ptr);
	exit(0);
}

int so_close(int keycode, t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	(void) keycode;
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	ft_printf("caca\n");
	ft_printf("%d\n", keycode);
	(void) game;
	return (0);
}

void main_render(t_game *game)
{
	ft_printf("main_render IN\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 800, "so_long");
	mlx_hook(game->win_ptr, 2, 0, so_close, game);
	mlx_loop_hook(game->mlx_ptr, &render_next_frame, &game);
	ft_printf("loop hook OK IN\n");
	mlx_key_hook(game->win_ptr, key_hook, game);
	mlx_loop(game->mlx_ptr);
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (ft_printf("Arguments count error\n"), 1);
	if (!ft_strnstr((const char *)argv[1], ".ber", ft_strlen((const char *)argv[1])))
		return (ft_printf("Map name error\n"));
	game.map.file_name = ft_strjoin("/maps/", (const char *) argv[1]);
	ft_printf("Before get_map main\n");
	game.map.fd = open(game.map.file_name, O_RDONLY);
	game.map.line = ft_file_linecount(game.map.fd);
	ft_get_map(&game);
	ft_print_map(&game);
	if (ft_check_map(&game))
		return (ft_printf("Map KO\n"), 1);
	game.mlx_ptr = mlx_init();
	set_img(&game);
	//ft_printf("%s\n", game.img.character);
	main_render(&game);
	//ft_printf("mlx_loop_hook OK\n");
}