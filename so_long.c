/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:26:58 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/22 13:47:16 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (ft_printf("Arguments count error\n"), 1);
	if (ft_parse_arg((const char *) argv[1])) 
		return (ft_printf("Map name error\n"));
	game.map.file_name = ft_strjoin("./maps/", (const char *) argv[1]);
	if (!game.map.file_name)
		return (1);
	game.map.fd = open(game.map.file_name, O_RDONLY);
	if (!game.map.fd)
		return (ft_free_struct(&game, 1), 1);
	game.map.line = ft_file_linecount(game.map.fd);
	ft_get_map(&game);
	ft_print_map(&game);
	if (ft_check_map(&game))
		return (ft_free_struct(&game, 3), 1);
	ft_is_map_solvable(&game);
	ft_set_img(&game);
	ft_main_render(&game);
}