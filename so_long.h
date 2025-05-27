/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:42:05 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/27 20:01:05 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define	SO_LONG_H

#	ifndef TILE_SIZE
#	 define TILE_SIZE 64
#	endif

#include "ft_printf/ft_printf.h"
#include "ft_getNextLine/get_next_line_bonus.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_sprites
{
	void	*background;
	void	*floor;
	void	*wall;
	void	*collect;
	void	*exit; 
	void	*player;
	void	*move[4];
} t_sprites;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			player_x;
	int			player_y;
	int			player_dir:
	//int			player_moving;
	//int			move_count;
	t_sprites	sprites;
} t_game;

char	**read_maps(int fd);
void	free_map(char **map);
int		check_map(t_game *game);
void	init_window(t_game *game);
void	draw_map(t_game *game);
void	load_draw_map(t_game *game);
int		handle_close(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
