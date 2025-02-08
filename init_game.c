/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:37:05 by qais              #+#    #+#             */
/*   Updated: 2025/02/08 17:54:33 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_texture(t_game *game)
{
	game->img->exit = mlx_xpm_file_to_image(game->mlx, "textures/E.xpm",
			&game->img->w, &game->img->h);
	if (!game->img->exit)
		exit_game(game);
	game->img->floor = mlx_xpm_file_to_image(game->mlx, "textures/F.xpm",
			&game->img->w, &game->img->h);
	if (!game->img->floor)
		exit_game(game);
	game->img->player = mlx_xpm_file_to_image(game->mlx, "textures/P.xpm",
			&game->img->w, &game->img->h);
	if (!game->img->player)
		exit_game(game);
	game->img->wall = mlx_xpm_file_to_image(game->mlx, "textures/W.xpm",
			&game->img->w, &game->img->h);
	if (!game->img->wall)
		exit_game(game);
	game->img->collect = mlx_xpm_file_to_image(game->mlx, "textures/C.xpm",
			&game->img->w, &game->img->h);
	if (!game->img->collect)
		exit_game(game);
}

t_game	*init_game(char **av)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		exit(EXIT_FAILURE);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		exit_game(game);
	game->img = ft_calloc(1, sizeof(t_imgs));
	if (!game->img)
		exit_game(game);
	game->map->arr = read_map(av, game);
	if (!game->map->arr)
		exit_game(game);
	check_map_errors(game);
	game->total_collectibles = count_collectibles(game->map);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game);
	init_texture(game);
	game->win = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->height * 64, "so_long");
	if (!game->win)
		exit_game(game);
	return (game);
}
