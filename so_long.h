/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:35:05 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/22 13:47:39 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GL_SILENCE_DEPRECATION 

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include "./includes/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_map
{
	char **full_map;
	int	map_sol[3];
	int p_position[2];
	char *file_name;
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
	int	win_width;
	int win_height;
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
	void *img_ptr;
	int	picked_c;
	int current_p_position[2];
	int	mov_count;
}	t_game;

void	ft_print_map(t_game *game);
void	ft_print_row(char **map, size_t row, size_t start, size_t line_count);
char	*ft_get_row(char **map, size_t row, size_t start, size_t line_count);
void	ft_free_struct(t_game *game, int error_code);
void	ft_free_one(t_game *game);
void	ft_free_two(t_game *game);
void	ft_free_three(t_game *game, int *error_code);
void	ft_free_four(t_game *game);
size_t	ft_file_linecount(int fd);
int		ft_parse_arg(const char *str);
int		ft_str_same_char_str(const char *str, int c);
size_t	ft_linecount(char **map);
int		ft_check_map(t_game *game);
void	ft_map_checker_initialize(t_game *game);
int 	ft_check_middle_lines(char *str, t_map *checker);
int		ft_map_checker_check(t_map *checker);
int		ft_check_map_top_bottom(char *str);
void	ft_map_error_case(int error);
int		ft_is_map_solvable(t_game *game);
void	ft_find_p_pos(t_game *game);
void	ft_get_map(t_game *game);
void	ft_set_img(t_game *game);
void	ft_img_first(t_game *game);
void	ft_set_img_void(t_game *game);
void	ft_set_img_path(t_game *game);
void	ft_other_render(t_game *game);
void	ft_background_render(t_game *game);
int		ft_render_next_frame(t_game *game);
void	ft_render_up(t_game *game);
void	ft_render_down(t_game *game);
void	ft_render_left(t_game *game);
void	ft_render_right(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
void	ft_main_render(t_game *game);
void	ft_print_mov(t_game *game);

void	ft_test();


#endif