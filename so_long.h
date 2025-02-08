/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qais <qais@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:43:04 by qais              #+#    #+#             */
/*   Updated: 2025/02/07 23:37:51 by qais             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <math.h>
# include "libft/libft.h"
# include <string.h>

typedef struct s_map
{
	char	**arr;
	int		fd;
	int		height;
	int		width;
	int		path;
}	t_map;

typedef struct s_imgs
{
	void	*player;
	void	*exit;
	void	*floor;
	void	*wall;
	void	*collect;
	int		w;
	int		h;
	int		count;
}		t_imgs;

typedef struct s_game
{
	t_imgs	*img;
	t_map	*map;
	void	*mlx;
	void	*win;
	int		x_p;
	int		y_p;
	int		collected;
	int		total_collectibles;
	int		move;
}		t_game;

char	**read_map(char **av, t_game *game);
int		is_valid(t_game *game);
int		count_map_lines(int fd);
int		count_collectibles(t_map *map);
int		is_square(t_game *game);
int		check_component(t_map *map);
int		is_there_collectable(t_game *game);
int		texture_count(t_game *game);
int		exit_game(t_game *game);
int		handle_key_press(int keycode, t_game *game);
int		validate_path(t_game *game);
void	ft_free(char **arr);
void	which_img(t_game *game, int i, int j);
void	redraw_map(t_game *game);
void	check_map_errors(t_game *game);
void	draw_map(t_map *map, t_game *game, t_imgs *img);
t_game	*init_game(char **av);

#endif