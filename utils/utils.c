/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:11:00 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/10 12:30:03 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_linecount(char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	ft_str_same_char_str(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_file_linecount(int fd)
{
	size_t	result;
	char	*line;

	result = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		result++;
	}
	close(fd);
	return (result);
}

void	ft_print_map(t_game *game)
{
	size_t	j;

	j = 0;
	while (j < game->map.line)
	{
		ft_printf("%s", game->map.full_map[j]);
		j++;
	}
}
