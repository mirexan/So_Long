/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:21:15 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/29 21:21:28 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*get_player_sprite(t_game *game)
{
	if (game->player_dir == 0)
	{
		if (game->player_moving == 0)
			return (game->sprites.player);
		return (game->sprites.player_1);
	}
	else if (game->player_dir == 1)
	{
		if (game->player_moving == 0)
			return (game->sprites.player_up);
		return (game->sprites.player_up_1);
	}
	else if (game->player_dir == 2)
	{
		if (game->player_moving == 0)
			return (game->sprites.player_left);
		return (game->sprites.player_left_1);
	}
	else
	{
		if (game->player_moving == 0)
			return (game->sprites.player_right);
		return (game->sprites.player_right_1);
	}

}

void	draw_player(t_game *game)
{
	int		x;
	int		y;
	void	*img;
	x = game->player_x * TILE_SIZE;
	y = game->player_y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.floor, x, y);
	img = get_player_sprite(game);
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}
