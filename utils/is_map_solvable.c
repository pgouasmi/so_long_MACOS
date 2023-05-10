/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_solvable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:20:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/10 11:40:43 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_p_pos(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	while (1)
	{
		if (ft_strchr((const char *)map->full_map[j], 'P'))
			break ;
		j++;
	}
	i = 0;
	while (map->full_map[j][i] != 'P')
		i++;
	map->p_position[0] = j;
	map->p_position[1] = i;
}

int	ft_map_is_solvable(t_map *map)
{
	ft_find_p_pos(map);
	return (0);
}
