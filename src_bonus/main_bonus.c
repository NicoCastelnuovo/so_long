/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:23:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/17 14:27:08 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_game(t_state *game)
{
	game->map = NULL;
	game->p.y = 0;
	game->p.x = 0;
	game->n.y = 0;
	game->n.x = 0;
	game->e = 0;
	game->is_exit = 0;
	game->c = 0;
	game->counter = 0;
	game->msg = NULL;
	game->mlx = NULL;
	game->img = NULL;
	game->txt = NULL;
}

int32_t	main(int argc, char **argv)
{
	t_state	game;

	init_game(&game);
	if (!validate(argc, argv, &game))
		return (free_all(&game), sl_error(1));
	if (!init_window(&game))
		return (free_all(&game), sl_error(2));
	mlx_loop_hook(game.mlx, handle_event, &game);
	mlx_key_hook(game.mlx, handle_key, &game);
	if (!draw_map(&game))
		return (free_all(&game), sl_error(3));
	mlx_loop(game.mlx);
	free_all(&game);
	mlx_terminate(game.mlx);
	return (ft_putendl_fd("****** Game Over ******", 1), 0);
}