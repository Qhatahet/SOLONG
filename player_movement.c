/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qais <qais@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:58:51 by qais              #+#    #+#             */
/*   Updated: 2025/02/07 06:01:22 by qais             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->x_p + x;
	new_y = game->y_p + y;
	if (game->map->arr[new_y][new_x] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->floor,
			game->x_p * 64, game->y_p * 64);
		game->x_p = new_x;
		game->y_p = new_y;
		if (game->map->arr[game->y_p][game->x_p] == 'C')
		{
			game->map->arr[game->y_p][game->x_p] = '0';
			game->total_collectibles--;
		}
		if (game->map->arr[game->y_p][game->x_p] == 'E' &&
			game->total_collectibles == 0)
		{
			exit_game(game);
		}
		game->move++;
		ft_printf("move count: %i\n", game->move);
		redraw_map(game);
	}
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 65361 || keycode == 97)
		move(game, -1, 0);
	else if (keycode == 65363 || keycode == 100)
		move(game, 1, 0);
	else if (keycode == 65362 || keycode == 119)
		move(game, 0, -1);
	else if (keycode == 65364 || keycode == 115)
		move(game, 0, 1);
	return (0);
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !arr[i])
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
