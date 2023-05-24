/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_solvable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:20:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/24 16:05:05 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_dup_map(t_map og_map)
{
	size_t	i;
	char	**result;

	ft_printf("line = %d\n\n", og_map.line);
	result = malloc(sizeof(char *) * (og_map.line + 1));
	if (!result)
		return (NULL);
	i = 0;
	result[og_map.line] = ft_strdup("");
	i = 0;
	while (i < og_map.line)
	{
		result[i] = ft_strdup(og_map.full_map[i]);
		if (!result[i])
			return (NULL);
		i++;
	}
	return (result);
}

void	ft_solve_map(t_dup_map *map_dup, int j, int i)
{
	if (map_dup->dup_map[j][i] == 'W')
		return ;
	if (map_dup->dup_map[j][i] == '0' || map_dup->dup_map[j][i] == 'C'
	|| map_dup->dup_map[j][i] == 'P' || map_dup->dup_map[j][i] == 'E')
	{
		if (map_dup->dup_map[j][i] == 'C')
			map_dup->c_count++;
		if (map_dup->dup_map[j][i] == 'E')
			map_dup->e_count = 1;
		map_dup->dup_map[j][i] = 'W';
		ft_solve_map(map_dup, j - 1, i);
		ft_solve_map(map_dup, j + 1, i);
		ft_solve_map(map_dup, j, i + 1);
		ft_solve_map(map_dup, j, i - 1);
	}
	return ;
}

int	ft_compare_items(t_map map, t_dup_map dup)
{
	return ((map.c_count - dup.c_count) + (map.e_count - dup.e_count));
}

void	ft_free_dup(t_dup_map *map)
{
	size_t	j;

	if (!map)
		return ;
	j = 0;
	while (map->dup_map[j])
	{
		free(map->dup_map[j]);
		j++;
	}
	free (map->dup_map);
}

int	ft_is_map_solvable(t_game *game)
{
	ft_find_p_pos(game);
	game->dup_map.dup_map = ft_dup_map(game->map);
	if (!game->dup_map.dup_map)
		return (ft_free_dup(&game->dup_map), 1);
	ft_solve_map(&game->dup_map, game->p_pos[0],
		game->p_pos[1]);
	if (ft_compare_items(game->map, game->dup_map))
		return (ft_printf("Error\nThe map is not solvable\n"),
			ft_free_dup(&game->dup_map), 1);
	return (ft_free_dup(&game->dup_map), 0);
}
