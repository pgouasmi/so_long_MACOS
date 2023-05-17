/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:02:35 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/16 19:04:20 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_other_render(t_game *game)
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

void ft_background_render(t_game *game)
{
	int i;
	size_t j;

	i = 0;
	j = 0;
	ft_printf("line : %d\n", game->map.line);
	while (j < game->map.line)
	{
		while(game->map.full_map[j][i])
		{
			if (game->map.full_map[j][i] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.wall_img, j * 64, i * 64);
			if (game->map.full_map[j][i] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor_img, j * 64, i * 64);
			i++;
		}
		i = 0;
		j++;
	}
}

int ft_render_next_frame(t_game *game)
{
	ft_printf("dans render next frame : line = %d\n\n", game->map.line);
	ft_background_render(game);
	ft_other_render(game);
	return (0);
}

int	ft_key_hook(int keycode, t_game *game)
{
	//ft_render_next_frame(game);
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		return (exit(1), 0);
	}
	if (keycode == 13)
		ft_render_up(game);
	if (keycode == 0)
		ft_render_left(game);
	if (keycode == 1)
		ft_render_down(game);
	if (keycode == 2)
		ft_render_right(game);
	ft_printf("p_position = [%d][%d]\n", game->current_p_position[0], game->current_p_position[1]);
	ft_printf("keycode : %d\n", keycode);
	ft_print_map(game);
	ft_printf("\n");
	return (0);
}
void	ft_game_win(t_game *game)
{
	ft_printf("Victory ! :D\n");
	ft_free_struct(game, 4);
}

void	ft_game_over(t_game *game)
{
	ft_printf("Game Over :/\n");
	ft_free_struct(game, 4);
}

void ft_open_door(t_game *game)
{
	(void) game;
}

void ft_render_up(t_game *game)
{
	if (game->map.full_map[game->current_p_position[0]-1][game->current_p_position[1]] == '1')
	{
		ft_printf("Movements count : %d\n", game->mov_count);
		return ;
	}
	else
	{
		if (game->map.full_map[game->current_p_position[0]-1][game->current_p_position[1]] == 'C')
		{
			game->picked_c++;
			if (game->picked_c == game->map.c_count)
				ft_open_door(game);
		}
		if (game->map.full_map[game->current_p_position[0]-1][game->current_p_position[1]] == 'E')
		{
			if (game->picked_c == game->map.c_count)
			{
				game->mov_count++;
				ft_printf("Movements count : %d\n", game->mov_count);
				ft_game_win(game);
			}
			ft_printf("Movements count : %d\n", game->mov_count);
			return ;
		}
		game->mov_count++;
		ft_printf("Movements count : %d\n", game->mov_count);
		game->map.full_map[game->current_p_position[0]][game->current_p_position[1]] = '0';
		game->map.full_map[game->current_p_position[0]-1][game->current_p_position[1]] = 'P';
		game->current_p_position[0]--;
	}
}

void ft_render_down(t_game *game)
{
	if (game->map.full_map[game->current_p_position[0]+1][game->current_p_position[1]] == '1')
	{
		ft_printf("Movements count : %d\n", game->mov_count);
		return ;
	}
	else
	{
		if (game->map.full_map[game->current_p_position[0]+1][game->current_p_position[1]] == 'C')
		{
			game->picked_c++;
			if (game->picked_c == game->map.c_count)
				ft_open_door(game);
		}
		if (game->map.full_map[game->current_p_position[0]+1][game->current_p_position[1]] == 'E')
		{
			if (game->picked_c == game->map.c_count)
			{
				game->mov_count++;
				ft_printf("Movements count : %d\n", game->mov_count);
				ft_game_win(game);
			}
			ft_printf("Movements count : %d\n", game->mov_count);
			return ;
		}
		game->mov_count++;
		ft_printf("Movements count : %d\n", game->mov_count);
		game->map.full_map[game->current_p_position[0]][game->current_p_position[1]] = '0';
		game->map.full_map[game->current_p_position[0]+1][game->current_p_position[1]] = 'P';
		game->current_p_position[0]++;
	}
}

void ft_render_left(t_game *game)
{
	if (game->map.full_map[game->current_p_position[0]][game->current_p_position[1]-1] == '1')
	{
		ft_printf("Movements count : %d\n", game->mov_count);
		return ;
	}
	else
	{
		if (game->map.full_map[game->current_p_position[0]][game->current_p_position[1]-1] == 'C')
		{
			game->picked_c++;
			if (game->picked_c == game->map.c_count)
				ft_open_door(game);
		}
		if (game->map.full_map[game->current_p_position[0]][game->current_p_position[1]-1] == 'E')
		{
			if (game->picked_c == game->map.c_count)
			{
				game->mov_count++;
				ft_printf("Movements count : %d\n", game->mov_count);
				ft_game_win(game);
			}
			ft_printf("Movements count : %d\n", game->mov_count);
			return ;
		}
		game->mov_count++;
		ft_printf("Movements count : %d\n", game->mov_count);
		game->map.full_map[game->current_p_position[0]][game->current_p_position[1]] = '0';
		game->map.full_map[game->current_p_position[0]][game->current_p_position[1]-1] = 'P';
		game->current_p_position[1]--;
	}
}

void ft_render_right(t_game *game)
{
	if (game->map.full_map[game->current_p_position[0]][game->current_p_position[1]+1] == '1')
	{
		ft_printf("Movements count : %d\n", game->mov_count);
		return ;
	}
	else
	{
		if (game->map.full_map[game->current_p_position[0]][game->current_p_position[1]+1] == 'C')
		{
			game->picked_c++;
			if (game->picked_c == game->map.c_count)
				ft_open_door(game);
		}
		if (game->map.full_map[game->current_p_position[0]][game->current_p_position[1]+1] == 'E')
		{
			if (game->picked_c == game->map.c_count)
			{
				game->mov_count++;
				ft_printf("Movements count : %d\n", game->mov_count);
				ft_game_win(game);
			}
			ft_printf("Movements count : %d\n", game->mov_count);
			return ;
		}
		game->mov_count++;
		ft_printf("Movements count : %d\n", game->mov_count);
		game->map.full_map[game->current_p_position[0]][game->current_p_position[1]] = '0';
		game->map.full_map[game->current_p_position[0]][game->current_p_position[1]+1] = 'P';
		game->current_p_position[1]++;
	}
}


void ft_main_render(t_game game)
{
	ft_printf("main_render IN\n");
	ft_printf("dans main render : line = %d\n\n", game.map.line);
	ft_printf("win_height : %d\n\n", game.img.win_height);
	ft_printf("win_width : %d\n\n", game.img.win_width);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.img.win_width, game.img.win_height, "so_long");
	game.mov_count = 0;
	mlx_loop_hook(game.mlx_ptr, &ft_render_next_frame, &game);
	mlx_hook(game.win_ptr, 2, 0, &ft_key_hook, &game);
	// mlx_hook(data->mlx_win, 17, 0, &end, data);
	// ft_printf("loop hook OK IN\n");
	// mlx_key_hook(game->win_ptr, key_hook, game);
	mlx_loop(game.mlx_ptr);
}
