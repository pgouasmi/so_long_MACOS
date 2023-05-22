/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:11:00 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/22 14:17:14 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_whitespace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int	ft_str_has_wrong_char(const char *str, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_is_whitespace(str[i]))
			return (1);
		while (set[j])
		{
			if (str[i] == set[j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_parse_arg(const char *str)
{
	size_t	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], ".ber", 4))
		return (1);
	if (ft_str_has_wrong_char(str, "#<>$+%%!*|{}?\\\"/:@&"))
		return (1);
	return (0);

}

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
		ft_printf("\n");
		j++;
	}
}
