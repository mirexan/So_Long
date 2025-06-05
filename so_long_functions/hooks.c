/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:16:54 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/27 21:46:52 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		handle_close(game);
	else if (keycode == 119 || keycode == 65362)
		move_up(game);
	else if (keycode == 115 || keycode == 65364)
		move_down(game);
	else if (keycode == 97 || keycode == 65361)
		move_left(game);
	else if (keycode == 100 || keycode == 65363)
		move_right(game);
	return (0);
}

int	handle_close(t_game *game)
{
	free_sprites(game);
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}