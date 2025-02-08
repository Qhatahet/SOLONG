/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qais <qais@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:50:43 by qais              #+#    #+#             */
/*   Updated: 2025/02/07 06:10:37 by qais             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_game *game, int x, int y, char **map_copy)
{
	if (map_copy[x][y] == '1')
		return ;
	if (map_copy[x][y] == 'C')
		game->collected--;
	if (map_copy[x][y] == 'E')
		game->map->path = 1;
	map_copy[x][y] = '1';
	flood_fill(game, x + 1, y, map_copy);
	flood_fill(game, x - 1, y, map_copy);
	flood_fill(game, x, y + 1, map_copy);
	flood_fill(game, x, y - 1, map_copy);
}

static void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->arr[i][j] == 'P')
			{
				game->y_p = i;
				game->x_p = j;
				return ;
			}
			j++;
		}
		i++;
	}
	exit_game(game);
}

static char	**copy_map(t_game *game)
{
	int		i;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * game->map->height);
	if (!map_copy)
		exit_game(game);
	i = 0;
	while (i < game->map->height)
	{
		map_copy[i] = ft_strdup(game->map->arr[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			exit_game(game);
		}
		i++;
	}
	return (map_copy);
}

int	validate_path(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	find_player_position(game);
	map_copy = copy_map(game);
	game->map->path = 0;
	game->total_collectibles = count_collectibles(game->map);
	game->collected = game->total_collectibles;
	flood_fill(game, game->y_p, game->x_p, map_copy);
	while (i < game->map->height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (!game->map->path)
		return (-1);
	if (game->collected > 0)
		return (-2);
	return (1);
}
