/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:03:16 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/24 16:08:14 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_e_case(t_game *game)
{
	if (game->picked_c == game->map.c_count)
	{
		game->mov_count++;
		ft_game_win(game);
	}
}

void	ft_other_render(t_game *game)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < game->map.line)
	{
		while (game->map.full_map[j][i])
		{
			if (game->map.full_map[j][i] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.char_img, i * 64, j * 64);
			if (game->map.full_map[j][i] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.collect_img, i * 64, j * 64);
			if (game->map.full_map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.cl_exit_img, i * 64, j * 64);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_background_render(t_game *game)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < game->map.line)
	{
		while (game->map.full_map[j][i])
		{
			if (game->map.full_map[j][i] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.wall_img, i * 64, j * 64);
			if (game->map.full_map[j][i] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.floor_img, i * 64, j * 64);
			if (game->map.full_map[j][i] == 'X')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.ennemy_img, i * 64, j * 64);
			i++;
		}
		i = 0;
		j++;
	}
}

int	ft_render_next_frame(t_game *game)
{
	ft_background_render(game);
	ft_other_render(game);
	return (0);
}
