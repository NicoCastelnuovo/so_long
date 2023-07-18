/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:49:15 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/18 12:17:51 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	win_controls(mlx_key_data_t keydata, t_state *game)
{
	if (keydata.key	== MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}

static void	pc_controls(mlx_key_data_t keydata, t_state *game)
{
	if (keydata.key	== MLX_KEY_W && is_possible_move(game, -1, 0, 'P'))
		pc_move(game, -1, 0);
	else if (keydata.key	== MLX_KEY_D && is_possible_move(game, 0, +1, 'P'))
		pc_move(game, 0, +1);
	else if (keydata.key	== MLX_KEY_S && is_possible_move(game, +1, 0, 'P'))
		pc_move(game, +1, 0);
	else if (keydata.key	== MLX_KEY_A && is_possible_move(game, 0, -1, 'P'))
		pc_move(game, 0, -1);
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_state	*game;

	game = (t_state *) param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (!game->is_end)
			pc_controls(keydata, game);
		win_controls(keydata, game);
	}
}
