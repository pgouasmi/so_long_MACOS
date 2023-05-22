/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:26:58 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/22 11:10:56 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*var malloc : game.map.file_name, */
int main(int argc, char **argv)
{
	t_game game;

	// (void) argc;
	// (void) argv;
	// ft_test(&game);

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

	ft_printf("main : line = %d\n\n", game.map.line);
	ft_get_map(&game);
	ft_printf("apres get_map : line = %d\n\n", game.map.line);
	ft_printf("Get map OK");
	ft_printf("%s\n", ft_get_row(game.map.full_map, 1, 0, game.map.line));
	ft_print_map(&game);
	if (ft_check_map(&game))
		return (ft_free_struct(&game, 3), 1);
	ft_printf("apres check_map : line = %d\n\n", game.map.line);
	// ft_is_map_solvable(game.map);
	ft_find_p_pos(&game);
	ft_printf("apres find p_pos : line = %d\n\n", game.map.line);
	ft_printf("p_position = [%d][%d]\n", game.current_p_position[0], game.current_p_position[1]);
	ft_set_img(&game);
	ft_printf("apres set_img : line = %d\n\n", game.map.line);
	ft_print_map(&game);
	ft_printf("avant render : line = %d\n\n", game.map.line);
	ft_main_render(&game);
}