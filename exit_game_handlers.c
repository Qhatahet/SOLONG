/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qais <qais@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:39:44 by qais              #+#    #+#             */
/*   Updated: 2025/02/07 06:39:02 by qais             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	which_error(int flag, t_game *game)
{
	if (flag == 1)
		ft_printf("\033[0;31mError\033[0m\nsomething wrong with the map\n");
	else if (flag == 2)
		ft_printf("\033[0;31mError\033[0m\nthere is no collectibles\n");
	else if (flag == 3)
		ft_printf("\033[0;31mError\033[0m\nyou got a hole in the wall\n");
	else if (flag == 4)
	{
		ft_printf("\033[0;31mError\033[0m\n");
		ft_printf("you got more than one player or exit\n");
	}
	else if (flag == 5)
		ft_printf("\033[0;31mError\033[0m\ninvalid component in the map\n");
	else if (flag == 6)
		ft_printf("\033[0;31mError\033[0m\ninvalid path\n");
	else if (flag == 7)
		ft_printf("\033[0;31mError\033[0m\nnot all collectibles reachable\n");
	exit_game(game);
}

void	check_map_errors(t_game *game)
{
	if (is_square(game) < 0)
		which_error(1, game);
	if (is_valid(game) < 0)
		which_error(3, game);
	if (is_there_collectable(game) < 0)
		which_error(2, game);
	if (validate_path(game) == -1)
		which_error(6, game);
	else if (validate_path(game) == -2)
		which_error(7, game);
	if (texture_count(game) < 0)
		which_error(4, game);
	if (check_component(game->map) < 0)
		which_error(5, game);
}

static void	cleanup_gnl(t_game *game)
{
	char	*buff;

	buff = get_next_line(game->map->fd);
	if (buff)
	{
		free(buff);
		buff = NULL;
	}
}

static void	free_allocated_memory(t_game *game)
{
	if (game->mlx)
		free(game->mlx);
	if (game->map->arr)
	{
		ft_free(game->map->arr);
		cleanup_gnl(game);
	}
	if (game->map)
		free(game->map);
	if (game->img)
		free(game->img);
	if (game)
		free(game);
}

int	exit_game(t_game *game)
{
	if (game->mlx && game)
	{
		if (game->img->collect)
			mlx_destroy_image(game->mlx, game->img->collect);
		if (game->img->player)
			mlx_destroy_image(game->mlx, game->img->player);
		if (game->img->exit)
			mlx_destroy_image(game->mlx, game->img->exit);
		if (game->img->floor)
			mlx_destroy_image(game->mlx, game->img->floor);
		if (game->img->wall)
			mlx_destroy_image(game->mlx, game->img->wall);
		if (game->win)
		{
			mlx_clear_window(game->mlx, game->win);
			mlx_destroy_window(game->mlx, game->win);
		}
		mlx_destroy_display(game->mlx);
	}
	free_allocated_memory(game);
	exit(0);
	return (0);
}
