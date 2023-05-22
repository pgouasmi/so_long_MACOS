/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_solvable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:20:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/22 13:46:40 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_p_pos(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	while (1)
	{
		if (ft_strchr((const char *)game->map.full_map[j], 'P'))
			break ;
		j++;
	}
	i = 0;
	while (game->map.full_map[j][i] != 'P')
		i++;
	game->current_p_position[0] = j;
	game->current_p_position[1] = i;
}

int	ft_is_map_solvable(t_game *game)
{
	ft_find_p_pos(game);
	return (0);
}
