/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:07:43 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/24 16:56:01 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_up(t_game *game)
{
	ft_print_mov(game);
	if (game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] == '1')
		return ;
	else
	{
		game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/char_up.xpm", &game->img.width, &game->img.height);
		if (game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] == 'C')
		{
			game->picked_c++;
			if (game->picked_c == game->map.c_count)
				ft_open_door(game);
		}
		if (game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] == 'E')
		{
			ft_e_case(game);
			return ;
		}
		if (game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] == 'X')
		{
			game->mov_count++;
			ft_game_over(game);
			return ;
		}
		game->mov_count++;
		game->map.full_map[game->p_pos[0]][game->p_pos[1]] = '0';
		game->map.full_map[game->p_pos[0] - 1][game->p_pos[1]] = 'P';
		game->p_pos[0]--;
	}
}

void	ft_render_down(t_game *game)
{
	ft_print_mov(game);
	if (game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] == '1')
		return ;
	else
	{
		game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/char_down.xpm", &game->img.width, &game->img.height);
		if (game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] == 'C')
		{
			game->picked_c++;
			if (game->picked_c == game->map.c_count)
				ft_open_door(game);
		}
		if (game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] == 'E')
		{
			ft_e_case(game);
			return ;
		}
		if (game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] == 'X')
		{
			game->mov_count++;
			ft_game_over(game);
			return ;
		}
		game->mov_count++;
		game->map.full_map[game->p_pos[0]][game->p_pos[1]] = '0';
		game->map.full_map[game->p_pos[0] + 1][game->p_pos[1]] = 'P';
		game->p_pos[0]++;
	}
}

void	ft_render_left(t_game *game)
{
	ft_print_mov(game);
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] == '1')
		return ;
	else
	{
		game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/char_left.xpm", &game->img.width, &game->img.height);
		if (game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] == 'C')
		{
			game->picked_c++;
			if (game->picked_c == game->map.c_count)
				ft_open_door(game);
		}
		if (game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] == 'E')
		{
			ft_e_case(game);
			return ;
		}
		if (game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] == 'X')
		{
			game->mov_count++;
			ft_game_over(game);
			return ;
		}
		game->mov_count++;
		game->map.full_map[game->p_pos[0]][game->p_pos[1]] = '0';
		game->map.full_map[game->p_pos[0]][game->p_pos[1] - 1] = 'P';
		game->p_pos[1]--;
	}
}

void	ft_render_right(t_game *game)
{
	ft_print_mov(game);
	if (game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] == '1')
		return ;
	else
	{
		game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/char_right.xpm", &game->img.width, &game->img.height);
		if (game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] == 'C')
		{
			game->picked_c++;
			if (game->picked_c == game->map.c_count)
				ft_open_door(game);
		}
		if (game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] == 'E')
		{
			ft_e_case(game);
			return ;
		}
		if (game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] == 'X')
		{
			game->mov_count++;
			ft_game_over(game);
			return ;
		}
		game->mov_count++;
		game->map.full_map[game->p_pos[0]][game->p_pos[1]] = '0';
		game->map.full_map[game->p_pos[0]][game->p_pos[1] + 1] = 'P';
		game->p_pos[1]++;
	}
}

int	ft_key_hook(int keycode, t_game *game)
{
	ft_print_mov(game);
	if (keycode == 53 || keycode == 17)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		ft_printf("Exit Game successfully\n");
		return (exit(1), 0);
	}
	else
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		if (keycode == 13)
			ft_render_up(game);
		if (keycode == 0)
			ft_render_left(game);
		if (keycode == 1)
			ft_render_down(game);
		if (keycode == 2)
			ft_render_right(game);
		ft_print_map(game->map.full_map);
		ft_printf("\n");
	}
	return (0);
}
