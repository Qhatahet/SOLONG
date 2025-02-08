/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qais <qais@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:55:24 by qais              #+#    #+#             */
/*   Updated: 2025/02/07 23:35:30 by qais             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->arr[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_map_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	close(fd);
	return (count);
}

void	which_img(t_game *game, int i, int j)
{
	if (game->map->arr[i][j] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img->exit, j * 64, i * 64);
	else if (game->map->arr[i][j] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img->wall, j * 64, i * 64);
	else if (game->map->arr[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->floor, j * 64, i * 64);
	else if (game->map->arr[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->player, game->x_p * 64, game->y_p * 64);
	else if (game->map->arr[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->floor, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->collect, j * 64, i * 64);
	}
}

char	**read_map(char **av, t_game *game)
{
	int	i;

	i = 0;
	game->map->fd = open(av[1], O_RDONLY);
	if (game->map->fd < 0)
		return (NULL);
	game->map->height = count_map_lines(game->map->fd);
	if (game->map->height < 2)
	{
		ft_printf("\033[0;31mError\033[0m\nempty map\n");
		exit_game(game);
	}
	game->map->arr = ft_calloc(game->map->height + 1, sizeof(char *));
	game->map->fd = open(av[1], O_RDONLY);
	if (!game->map->arr || game->map->fd < 0)
		return (NULL);
	while (i < game->map->height)
	{
		game->map->arr[i] = get_next_line(game->map->fd);
		game->map->arr[i][ft_strlen(game->map->arr[i])] = '\0';
		i++;
	}
	game->map->width = ft_strlen(game->map->arr[0]) - 1;
	close(game->map->fd);
	return (game->map->arr);
}
