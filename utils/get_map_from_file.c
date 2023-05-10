/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:18:02 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/10 12:32:10 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map(t_game *game)
{
	size_t	i;
	char	*line;

	game->map.fd = open(ft_strjoin("..", game->map.file_name), O_RDONLY);
	game->map.line = ft_file_linecount(game->map.fd);
	ft_printf("map.line = %d\n", game->map.line);
	if (game->map.line < 3)
	{
		ft_printf("trop peu de lignes, erreur\n");
		return ;
	}
	game->map.full_map = malloc(sizeof(char *) * (game->map.line));
	game->map.full_map[game->map.line] = ft_strdup("");
	i = 0;
	game->map.fd = open(game->map.file_name, O_RDONLY);
	ft_printf("file name = %s\n", game->map.file_name);
	ft_printf("fd = %d\n", game->map.fd);
	while (1)
	{
		line = ft_strtrim((const char *)get_next_line(game->map.fd), "'\n'");
		// ft_printf("line = %s\n", line);
		if (!line)
			break ;
		game->map.full_map[i] = ft_strdup((const char *)line);
		free(line);
		i++;
	}
	close(game->map.fd);
}
