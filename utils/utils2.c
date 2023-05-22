/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:26:40 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/22 14:30:09 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_get_row(char **map, size_t row, size_t start, size_t line_count)
{
	size_t	length;
	size_t	i;
	char	*result;

	length = line_count - start;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	i = 0;
	while (start < line_count)
	{
		result[i] = map[start][row];
		start++;
		i++;
	}
	return (result);
}

void	ft_print_row(char **map, size_t row, size_t start, size_t line_count)
{
	while (start < line_count)
	{
		ft_printf("%c\n", map[start][row]);
		start++;
	}
}

size_t	ft_linecount(char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
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
		ft_printf("\n");
		j++;
	}
}
