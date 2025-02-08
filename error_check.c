/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qais <qais@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:57:32 by qais              #+#    #+#             */
/*   Updated: 2025/02/07 06:17:30 by qais             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_component(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->arr[i])
	{
		j = 0;
		while (map->arr[i][j])
		{
			if (map->arr[i][j] != '1' && map->arr[i][j] != '0' &&
				map->arr[i][j] != 'P' && map->arr[i][j] != 'C' &&
				map->arr[i][j] != 'E' && map->arr[i][j] != '\n')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid(t_game *game)
{
	int	i;
	int	h;
	int	w;

	i = 0;
	h = game->map->height;
	w = game->map->width;
	while (i < w)
	{
		if (game->map->arr[0][i] != '1' || game->map->arr[h - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 1;
	while (i < h - 1)
	{
		if (game->map->arr[i][0] != '1' || game->map->arr[i][w - 1] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	is_square(t_game *game)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(game->map->arr[game->map->height - 1]) + 1;
	while (i < game->map->height - 1)
	{
		if (ft_strlen(game->map->arr[i]) != j)
			return (-1);
		i++;
	}
	return (1);
}

int	is_there_collectable(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (game->map->arr[i] && i < game->map->height)
	{
		if (!ft_strchr(game->map->arr[i], 'C'))
			j = -1;
		else
		{
			j = 1;
			break ;
		}
		i++;
	}
	return (j);
}

int	texture_count(t_game *game)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;

	j = 0;
	i = 0;
	p_count = 0;
	e_count = 0;
	while (game->map->arr[i])
	{
		j = 0;
		while (game->map->arr[i][j])
		{
			if (game->map->arr[i][j] == 'P')
				p_count++;
			else if (game->map->arr[i][j] == 'E')
				e_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1 || e_count != 1)
		return (-1);
	return (1);
}
