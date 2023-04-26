/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:26:58 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/26 17:11:01 by pgouasmi         ###   ########.fr       */
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

int ft_map_checker_check(map_check checker)
{
	ft_printf("C = %d, P = %d, E = %d\n", checker.is_c, checker.is_p, checker.is_e);
	if (checker.is_c < 1)
		return (ft_printf("No collectibles error\n"), 1);
	if (checker.is_p != 1)
		return (ft_printf("No position error\n"), 1);
	if (checker.is_e != 1)
		return (ft_printf("No exit error\n"), 1);
	return (0);
}

int ft_check_middle_lines(char *str, map_check *checker)
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
				checker->is_e++;
			if (str[i] == 'C')
				checker->is_c++;
			if (str[i] == 'P')
				checker->is_p++;
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

void	ft_map_checker_initialize(map_check *checker)
{
	checker->is_c = 0;
	checker->is_e = 0;
	checker->is_p = 0;
}

void	ft_find_p_pos(char **map, int **p_position)
{
	int j;
	int i;

	j = 0;
	while (1)
	{
		if (ft_strchr((const char *)map[j], 'P'))
			break ;
		j++;
	}
	i = 0;
	while (map[j][i] != 'P')
		i++;
	*p_position[0] = j;
	*p_position[1] = i;
}

int	ft_map_is_solvable(char **map, map_check checker)
{
	int *p_position;

	p_position = malloc(sizeof(int) * 2);
	ft_find_p_pos(map, &p_position);
	ft_printf("%c\n", map[0][ft_strlen(map[0])]);
	checker.is_c++;
	return (0);
}

int	ft_check_map(char **map, size_t line_count)
{
	size_t	j;
	map_check checker;
	size_t first_len;

	ft_map_checker_initialize(&checker);
	first_len = ft_strlen(ft_strtrim((const char *)map[0], "\n"));
	j = 0;
	while (j < line_count)
	{
		if (j == 0 || j == line_count - 1)
		{
			if ((ft_strlen(ft_strtrim((const char *)map[j], "\n")) != first_len)
				|| (!ft_check_map_top_bottom(ft_strtrim((const char *)map[j], "'\n'"))))
				return (1);
		}
		if (j >= 1 && j < (line_count - 1))
		{
			if ((ft_strlen(ft_strtrim((const char *)map[j], "\n")) != first_len) 
				|| (ft_check_middle_lines(ft_strtrim((const char *)map[j], "'\n'"), &checker)))
				return (1);
		}
		j++;
	}
	if (ft_map_checker_check(checker))
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
	return (result);
}

char **get_map(int fd, char **argv, size_t *line_count, t_map *map)
{
	char	**map;
	size_t	i;
	char *line;
	char *open_var;

	*line_count = ft_file_linecount(fd);
	if (*line_count < 3)
		return (ft_printf("trop peu de lignes, erreur\n"), NULL);
	map = malloc(sizeof(char *) * *line_count);
	map[*line_count] = ft_strdup("");
	i = 0;
	open_var = ft_strjoin("./maps/", (const char *) argv[1]);
	fd = open(open_var, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = ft_strdup((const char *)line);
		free(line);
		i++;
	}
	map.;
}

int main(int argc, char **argv)
{
	int fd;
	char *open_var;
	size_t	line_count;
	void *mlx_ptr;
	void *win_ptr;
	t_map map;


	if (argc != 2)
		return (ft_printf("Arguments count error\n"), 1);
	if (!ft_strnstr((const char *)argv[1], ".ber", ft_strlen((const char *)argv[1])))
		return (ft_printf("Map name error\n"));
	open_var = ft_strjoin("./maps/", (const char *) argv[1]);
	fd = open(open_var, O_RDONLY);
	get_map(fd, argv, &line_count, &map);
	if (ft_check_map(map, line_count))
		return (ft_printf("Map KO\n"), 1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "so_long");
	mlx_loop(mlx_ptr);
	int width, height;
	void	*img = mlx_xpm_file_to_image(mlx_ptr, "./sprites/character.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
}