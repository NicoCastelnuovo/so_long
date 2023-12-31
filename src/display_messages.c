/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:07:27 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 14:58:09 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_end(t_state *game)
{
	int	mid_y;
	int	mid_x;

	mid_y = (game->mlx->height / 2) - 10;
	mid_x = (game->mlx->width / 2) - ((ft_strlen("Game Over [Esc]") * 10) / 2);
	game->end_img = mlx_put_string(game->mlx, "Game Over [Esc]", mid_x, mid_y);
}

void	display_steps(t_state *game)
{
	game->data->steps += 1;
	ft_printf("Steps: %d\n", game->data->steps);
}
