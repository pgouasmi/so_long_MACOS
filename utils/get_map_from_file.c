/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:18:02 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/22 14:43:30 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_get_map(t_game *game)
{
	size_t	i;
	char	*line;

	i = 0;
	game->map.fd = open(game->map.file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(game->map.fd);
		if (!line)
			break ;
		game->map.full_map[i] = ft_strdup(ft_strtrim((const char *)line, "\n"));
		if (!game->map.full_map[i])
			return (ft_free_struct(game, 2), exit(1));
		free(line);
		i++;
	}
	close(game->map.fd);
}

void	ft_get_map_setup(t_game *game)
{
	if (game->map.line < 3)
	{
		ft_printf("trop peu de lignes, erreur\n");
		ft_free_struct(game, 1);
	}
	game->map.full_map = malloc(sizeof(char *) * (game->map.line));
	if (!game->map.full_map)
		return (ft_free_struct(game, 1));
	game->map.full_map[game->map.line] = ft_strdup("");
	if (!game->map.full_map[game->map.line])
		return (ft_free_struct(game, 2), exit(1));
	ft_get_map(game);
}
