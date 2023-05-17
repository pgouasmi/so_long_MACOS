/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:46:49 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/11 19:22:40 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_four(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.wall_img);
	mlx_destroy_image(game->mlx_ptr, game->img.floor_img);
	mlx_destroy_image(game->mlx_ptr, game->img.collect_img);
	mlx_destroy_image(game->mlx_ptr, game->img.char_img);
	mlx_destroy_image(game->mlx_ptr, game->img.cl_exit_img);
	mlx_destroy_image(game->mlx_ptr, game->img.op_exit_img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
}

void	ft_free_three(t_game *game, int *error_code)
{
	size_t	j;

	j = 0;
	while (j < game->map.line)
	{
		if (game->map.full_map[j])
			free(game->map.full_map[j]);
		j++;
	}
	(*error_code)--;
	ft_free_two(game);
}

void	ft_free_two(t_game *game)
{
	free(game->map.full_map);
}

void	ft_free_one(t_game *game)
{
	free(game->map.file_name);
}

void	ft_free_struct(t_game *game, int error_code)
{
	while (error_code)
	{
		if (error_code == 1)
			ft_free_one(game);
		if (error_code == 2)
			ft_free_two(game);
		if (error_code == 3)
			ft_free_three(game, &error_code);
		if (error_code == 4)
			ft_free_four(game);
		error_code--;
	}
	exit (1);
}
