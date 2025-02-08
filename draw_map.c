/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:33:03 by qais              #+#    #+#             */
/*   Updated: 2025/02/08 15:26:21 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	redraw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			which_img(game, i, j);
			j++;
		}
		i++;
	}
	if (!mlx_put_image_to_window(game->mlx, game->win, game->img->player,
			game->x_p * 64, game->y_p * 64))
		return ;
}

static void	put_img_into_window(t_game *game, t_imgs *img, int i, int j)
{
	if (game->map->arr[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			img->exit, j * 64, i * 64);
	else if (game->map->arr[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			img->wall, j * 64, i * 64);
	else if (game->map->arr[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			img->floor, j * 64, i * 64);
	else if (game->map->arr[i][j] == 'P')
	{
		game->x_p = j;
		game->y_p = i;
		mlx_put_image_to_window(game->mlx, game->win,
			img->player, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx, game->win,
			img->player, j * 64, i * 64);
	}
	else if (game->map->arr[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			img->floor, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx, game->win,
			img->collect, j * 64, i * 64);
	}
}

void	draw_map(t_map *map, t_game *game, t_imgs *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			put_img_into_window(game, img, i, j);
			j++;
		}
		i++;
	}
}
