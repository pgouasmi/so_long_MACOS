/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:13:34 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/10 12:11:20 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_top_bottom(char *str)
{
	return (ft_str_same_char_str(str, '1'));
}

int	ft_map_checker_check(t_map *checker)
{
	if (checker->c_count < 1)
		return (ft_printf("No collectibles error\n"), 1);
	if (checker->p_count != 1)
		return (ft_printf("No position error\n"), 1);
	if (checker->e_count != 1)
		return (ft_printf("No exit error\n"), 1);
	return (0);
}

int	ft_check_middle_lines(char *str, t_map *checker)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || i == ft_strlen(str))
		{
			if (str[i] != '1')
				return (1);
		}
		else
		{
			if (ft_strtrim((const char *)str, "10PCE"))
				return (1);
			if (str[i] == 'E')
				checker->e_count++;
			if (str[i] == 'C')
				checker->c_count++;
			if (str[i] == 'P')
				checker->p_count++;
		}
		i++;
	}
	return (0);
}

void	ft_map_checker_initialize(t_game *game)
{
	game->map.c_count = 0;
	game->map.e_count = 0;
	game->map.p_count = 0;
}

/*need to add map is solvable*/

int	ft_check_map(t_game *game)
{
	size_t	j;

	ft_map_checker_initialize(game);
	game->map.row = ft_strlen(game->map.full_map[0]);
	j = 0;
	while (j < game->map.line)
	{
		if (j == 0 || j == game->map.line - 1)
		{
			if ((ft_strlen(game->map.full_map[j]) != game->map.row)
				|| (!ft_check_map_top_bottom(game->map.full_map[j])))
				return (1);
		}
		if (j >= 1 && j < (game->map.line - 1))
		{
			if ((ft_strlen(game->map.full_map[j]) != game->map.row)
				|| (ft_check_middle_lines(game->map.full_map[j], &game->map)))
				return (1);
		}
		j++;
	}
	if (ft_map_checker_check(&game->map))
		return (1);
	return (0);
}
