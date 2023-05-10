/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:35:05 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/10 12:31:22 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GL_SILENCE_DEPRECATION 

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <./includes/libft.h>
# include "./minilibx_opengl_20191021/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_map
{
	char **full_map;
	int p_position[2];
	const char *file_name;
	int fd;
	size_t row;
	size_t line;
	int p_count;
	int c_count;
	int e_count;
}		t_map; 

typedef struct s_img
{
	int width;
	int height;
	const char *path;
	char *character;
	char *wall;
	char *floor;
	char *collectible;
	char *exit_closed;
	char *exit_open;
	char *ennemy;
	void *char_img;
	void *wall_img;
	void *floor_img;
	void *collect_img;
	void *cl_exit_img;
	void *op_exit_img;
	void *ennemy_img;
}	t_img;

typedef struct s_game
{
	t_map map;
	t_img img;
	void *mlx_ptr;
	void *win_ptr;
	int	picked_c;
	int current_p_position[2];
}	t_game;

void	ft_print_map(t_game *game);
size_t	ft_file_linecount(int fd);
int		ft_str_same_char_str(const char *str, int c);
size_t	ft_linecount(char **map);
int		ft_check_map(t_game *game);
void	ft_map_checker_initialize(t_game *game);
int 	ft_check_middle_lines(char *str, t_map *checker);
int 	ft_map_checker_check(t_map *checker);
int		ft_check_map_top_bottom(char *str);
int		ft_map_is_solvable(t_map *map);
void	ft_find_p_pos(t_map *map);
void	ft_get_map(t_game *game);



#endif