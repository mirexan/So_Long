/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:00:47 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/27 22:06:43 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_map(t_game *game)
{
	int	x;
	int	y;

	y = game->player_y;
	x = game->player_x;
	if (game->map[y][x] == 'C')
	{
		game->collected++;
		game->map[y][x] = '0';
	}
	if (game->map[y][x] == 'E' && game->collected == game->total_collect)
		handle_close(game);
}

void	move_up(t_game	*game)
{
	if (game->player_y > 0 && (
			game->map[game->player_y -1][game->player_x] != '1'))
	{
		update_map(game);
		game->player_y--;
		game->player_dir = 1;
		game->move_count++;
		ft_printf("Moves : %d\n", game->move_count);
		load_draw_map(game);
		game->player_moving = 1 - game->player_moving;
	}
}

void	move_down(t_game	*game)
{
	int	h;

	h = 0;
	while (game->map[h])
		h++;
	if (game->player_y + 1 < h && (
			game->map[game->player_y + 1][game->player_x] != '1'))
	{
		update_map(game);
		game->player_y++;
		game->player_dir = 0;
		game->move_count++;
		ft_printf("Moves : %d\n", game->move_count);
		load_draw_map(game);
		game->player_moving = 1 - game->player_moving;
	}
}

void	move_left(t_game	*game)
{
	if (game->player_x > 0 && (
			game->map[game->player_y][game->player_x - 1] != '1'))
	{
		update_map(game);
		game->player_x--;
		game->player_dir = 2;
		game->move_count++;
		ft_printf("Moves : %d\n", game->move_count);
		load_draw_map(game);
		game->player_moving = 1 - game->player_moving;
	}
}

void	move_right(t_game	*game)
{
	int	w;

	w = ft_strlen(game->map[game->player_y]);
	if ((game->player_x + 1 < w) && (
			game->map[game->player_y][game->player_x + 1] != '1'))
	{
		update_map(game);
		game->player_x++;
		game->player_dir = 3;
		game->move_count++;
		ft_printf("Moves : %d\n", game->move_count);
		load_draw_map(game);
		game->player_moving = 1 - game->player_moving;
	}
}
