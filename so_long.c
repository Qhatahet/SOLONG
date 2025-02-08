/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qais <qais@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:30:19 by qhatahet          #+#    #+#             */
/*   Updated: 2025/02/07 23:38:21 by qais             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("\033[0;31mError\033[0m\nIncorrect number of arguments.\n");
		return (1);
	}
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
	{
		ft_printf("\033[0;31mError\033[0m\nwrong map extintion\n");
		return (1);
	}
	game = init_game(argv);
	draw_map(game->map, game, game->img);
	mlx_hook(game->win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
