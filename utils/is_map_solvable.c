/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_solvable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:20:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/23 11:15:02 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_dup_map(t_map og_map)
{
	size_t	i;
	char **result;

	ft_printf("line = %d\n\n", og_map.line);
	result = malloc(sizeof(char *) * (og_map.line + 1));
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

void ft_solve_map(t_dup_map *map_dup, int j, int i)
{
	if (map_dup->dup_map[j][i] == 'X')
		return ;
	if (map_dup->dup_map[j][i] == '0' || map_dup->dup_map[j][i] == 'C'
	|| map_dup->dup_map[j][i] == 'P' || map_dup->dup_map[j][i] == 'E')
		{
			if (map_dup->dup_map[j][i] == 'C')
				map_dup->c_count++;
			if (map_dup->dup_map[j][i] == 'E')
				map_dup->e_count = 1;
			map_dup->dup_map[j][i] = '1';
			ft_solve_map(map_dup, j - 1, i);
			ft_solve_map(map_dup, j + 1, i);
			ft_solve_map(map_dup, j, i + 1);
			ft_solve_map(map_dup, j, i - 1);
		}
		return ;
}

int ft_compare_items(t_map map, t_dup_map dup)
{
	return ((map.c_count - dup.c_count) + (map.e_count - dup.e_count));
}

void	ft_free_dup(t_dup_map *map)
{
	size_t	j;

	if (!map)
		return ;
	j = 0;
	while(map->dup_map[j])
	{
		free(map->dup_map[j]);
		j++;
	}
	free (map);
}

int	ft_is_map_solvable(t_game *game)
{
	ft_find_p_pos(game);
	game->dup_map.dup_map = ft_dup_map(game->map); //malloc a free
	ft_solve_map(&game->dup_map, game->current_p_position[0], game->current_p_position[1]);
	ft_printf("OG MAP : C = %d\n E = %d\n", game->map.c_count, game->map.e_count);
	ft_printf("DUP MAP : C = %d\n E = %d\n", game->dup_map.c_count, game->dup_map.e_count);
	if (ft_compare_items(game->map, game->dup_map))
		return (ft_printf("Error\nThe map is not solvable\n"), ft_free_dup(&game->dup_map), 1);
	ft_print_map(game->dup_map.dup_map);
	return (0);
}
