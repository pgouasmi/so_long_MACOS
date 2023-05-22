/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:13:34 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/22 14:35:45 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_map_error_case(int error)
{
	if (error == 1)
		ft_printf("Error\nMap is not rectangular\n");
	if (error == 2 || error == 3)
		ft_printf("Error\nMap's borders are not 1\n");
	if (error == 4)
		ft_printf("Error\nUnknown character(s) in the map\n");
}

int	ft_check_map_top_bottom(char *str)
{
	return (ft_str_same_char_str(str, '1'));
}

int	ft_check_middle_lines(char *str, t_map *checker)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || i == ft_strlen(str) - 1)
		{
			if (str[i] != '1')
				return (1);
		}
		else
		{
			if ((ft_strtrim((const char *)str, "10PCE"))[0])
				return (2);
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

int	ft_check_map(t_game *game)
{
	size_t	j;
	int		flag_middle;

	ft_map_checker_initialize(game);
	j = -1;
	while (++j < game->map.line)
	{
		if (ft_strlen(game->map.full_map[j]) != game->map.row)
			return (ft_map_error_case(1), 1);
		if (j == 0 || j == game->map.line - 1)
		{
			if (!ft_check_map_top_bottom(game->map.full_map[j]))
				return (ft_map_error_case(2), 1);
		}
		else
		{
			flag_middle = ft_check_middle_lines(game->map.full_map[j],
					&game->map);
			if (flag_middle == 1)
				return (ft_map_error_case(3), 1);
			if (flag_middle == 2)
				return (ft_map_error_case(4), 1);
		}
	}
	return (0);
}
