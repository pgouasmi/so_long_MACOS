/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:21:51 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/15 15:44:40 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_is_obstacle_connected(char **map, size_t j; size_t i)
// {
// 	if (map[j + 1][i] && j != line - 1)
// 		j++;
// 	if (map[j - 1][i] && j != 0)
// 		j--;
// 	if (map[j][i + 1] && i != row - 1)
// 		i++;
// 	if (map[j][i - 1] && i != 0)
// 		i--;
// }

// void	ft_obstacle_detected(char **map, size_t j, size_t i)
// {
// 	if (ft_is_obstacle_connected(map, j, i))

// }

// void	ft_trim_map(t_map *map)
// {
// 	size_t	j;
// 	size_t	i;

// 	j = 1;
// 	while (j < map->line - 1)
// 	{
// 		i = 1;
// 		while (i < map->row - 1)
// 		{
// 			if (map->full_map[j][i] == '1')
// 				ft_obstacle_detected(map->full_map, j, i);
// 			i++;
// 		}
// 		j++;
// 	}
// }


// int	ft_is_map_solvable(t_map map)
// {
// 	ft_trim_map(&map);
// 	return (1);
// }