/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:26:58 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/02 12:54:33 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int ft_check_map_top_bottom(char *str)
{
	return (ft_str_same_char_str(str, '1'));
}

int ft_map_checker_check(t_map *checker)
{
	ft_printf("C = %d, P = %d, E = %d\n", checker->c_count, checker->p_count, checker->e_count);
	if (checker->c_count < 1)
		return (ft_printf("No collectibles error\n"), 1);
	if (checker->p_count != 1)
		return (ft_printf("No position error\n"), 1);
	if (checker->e_count != 1)
		return (ft_printf("No exit error\n"), 1);
	return (0);
}
int ft_check_middle_lines(char *str, t_map *checker)
{
	size_t i;
	size_t last;

	i = 0;
	last = ft_strlen(str);
	while (str[i])
	{
		if (i == 0 || i == last)
		{
			if (str[i] != '1')
				return (1);
		}
		else
			if (str[i] != '1' && str[i] != '0' && str[i] != 'P' && str[i] != 'C' && str[i] != 'E')
				return (1);
			if (str[i] == 'E')
				checker->e_count++;
			if (str[i] == 'C')
				checker->c_count++;
			if (str[i] == 'P')
				checker->p_count++;
		i++;
	}
	return (0);
}

size_t ft_linecount(char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	ft_map_checker_initialize(t_game *game)
{
	game->map.c_count = 0;
	game->map.e_count = 0;
	game->map.p_count = 0;
}

void	ft_find_p_pos(t_map *map)
{
	int j;
	int i;

	j = 0;
	while (1)
	{
		if (ft_strchr((const char *)map->full_map[j], 'P'))
			break ;
		j++;
	}
	i = 0;
	while (map->full_map[j][i] != 'P')
		i++;
	map->p_position[0] = j;
	map->p_position[1] = i;
}

int	ft_map_is_solvable(t_map *map)
{
	ft_find_p_pos(map);
	//ft_printf("%c\n", map[0][ft_strlen(map[0])]);
	//map.checker.is_c++;
	return (0);
}

int	ft_check_map(t_game *game)
{
	size_t	j;

	ft_map_checker_initialize(game);
	game->map.row = ft_strlen(ft_strtrim((const char *)game->map.full_map[0], "\n"));
	j = 0;
	while (j < game->map.line)
	{
		if (j == 0 || j == game->map.line - 1)
		{
			if ((ft_strlen(ft_strtrim((const char *)game->map.full_map[j], "\n")) != game->map.row)
				|| (!ft_check_map_top_bottom(ft_strtrim((const char *)game->map.full_map[j], "'\n'"))))
				return (1);
		}
		if (j >= 1 && j < (game->map.line - 1))
		{
			if ((ft_strlen(ft_strtrim((const char *)game->map.full_map[j], "\n")) != game->map.row) 
				|| (ft_check_middle_lines(ft_strtrim((const char *)game->map.full_map[j], "'\n'"), &game->map)))
				return (1);
		}
		j++;
	}
	if (ft_map_checker_check(&game->map))
		return (1);
	ft_printf("Map OKKKKKK\n");
	// if (ft_map_is_solvable(map, checker))
	// 	return (ft_printf("map is unsolvable\n"), 1);
	return (0);
}

size_t ft_file_linecount(int fd)
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

void	get_map(t_game *game)
{
	size_t	i;
	char *line;

	game->map.line = ft_file_linecount(game->map.fd);
	if (game->map.line < 3)
	{
		ft_printf("trop peu de lignes, erreur\n");
		return ;
	}
	game->map.full_map = malloc(sizeof(char *) * (game->map.line));
	game->map.full_map[game->map.line] = ft_strdup("");
	i = 0;
	game->map.fd = open(game->map.file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(game->map.fd);
		if (!line)
			break ;
		game->map.full_map[i] = ft_strdup((const char *)line);
		free(line);
		i++;
	}
}

void	set_img(t_game *game)
{
	game->img.width = 64;
	game->img.height = 64;
	game->img.path = "./sprites/";
	game->img.character = ft_strjoin(game->img.path, "character.xpm");
	game->img.wall = ft_strjoin(game->img.path, "obstacle.xpm");
	game->img.floor = ft_strjoin(game->img.path, "grass.xpm");
	game->img.collectible = ft_strjoin(game->img.path, "ring.xpm");
	game->img.exit_closed = ft_strjoin(game->img.path, "closed_door.xpm");
	game->img.exit_open = ft_strjoin(game->img.path, "open_door.xpm");
	game->img.ennemy = ft_strjoin(game->img.path, "ennemy.xpm");
	game->img.char_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.character, &(game->img.width), &(game->img.height));
	game->img.wall_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.wall, &(game->img.width), &(game->img.height));
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.floor, &(game->img.width), &(game->img.height));
	game->img.collect_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.collectible, &(game->img.width), &(game->img.height));
	game->img.cl_exit_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.exit_closed, &(game->img.width), &(game->img.height));
	game->img.op_exit_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.exit_open, &(game->img.width), &(game->img.height));
	game->img.ennemy_img = mlx_xpm_file_to_image(game->mlx_ptr, game->img.ennemy, &(game->img.width), &(game->img.height));

}

void other_render(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map.full_map[j])
	{
		while(game->map.full_map[j][i])
		{
			if (game->map.full_map[j][i] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.collect_img, j * 64, i * 64);
			if (game->map.full_map[j][i] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.char_img, j * 64, i * 64);
			if (game->map.full_map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.cl_exit_img, j * 64, i * 64);
			i++;
		}
		i = 0;
		j++;
	}
}

void background_render(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map.full_map[j])
	{
		while(game->map.full_map[j][i])
		{
			if (game->map.full_map[j][i] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.wall_img, 64, 64);
			if (game->map.full_map[j][i] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor_img, 64, 64);
			i++;
		}
		i = 0;
		j++;
	}
}

int render(t_game *game)
{
	background_render(game);
	other_render(game);
	return (0);
}

int	end(t_game *game)
{
	int		i;

	i = 0;
	if (game->map.full_map != NULL)
	{
		while (game->map.full_map[i] != NULL)
		{
			free(game->map.full_map[i]);
			i++;
		}
		free(game->map.full_map);
		mlx_destroy_image(game->mlx_ptr, game->img.wall_img);
		mlx_destroy_image(game->mlx_ptr, game->img.floor_img);
		mlx_destroy_image(game->mlx_ptr, game->img.collect_img);
		mlx_destroy_image(game->mlx_ptr, game->img.char_img);
		mlx_destroy_image(game->mlx_ptr, game->img.cl_exit_img);
		mlx_destroy_image(game->mlx_ptr, game->img.op_exit_img);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	free(game->mlx_ptr);
	exit(0);
}

void core_render(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 800, "so_long");
	mlx_loop_hook(game->mlx_ptr, &render, &game);
	// mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &key_press, game);
	// mlx_hook(game->win_ptr, 17, 0, &end, data);
	mlx_loop(game->mlx_ptr);
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (ft_printf("Arguments count error\n"), 1);
	if (!ft_strnstr((const char *)argv[1], ".ber", ft_strlen((const char *)argv[1])))
		return (ft_printf("Map name error\n"));
	game.map.file_name = ft_strjoin("./maps/", (const char *) argv[1]);
	game.map.fd = open(game.map.file_name, O_RDONLY);
	get_map(&game);
	if (ft_check_map(&game))
		return (ft_printf("Map KO\n"), 1);
	game.mlx_ptr = mlx_init();
	set_img(&game);
	ft_printf("%s\n", game.img.character);
	core_render(&game);
	ft_printf("mlx_loop_hook OK\n");
}