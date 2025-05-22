/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:42:05 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/22 21:12:04 by mregada-         ###   ########.fr       */
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
	//void	*player_up;
	void	*player;
	//void	*player_left;
	//void	*player_rigth;
} t_sprites;

char	**read_maps(int fd);
void	free_map(char **map);
int		check_map(char **map);
void	init_window(char **map);
void	draw_map(void *mlx, void *win, char **map, t_sprites sprite);
void	load_draw_map(void *mlx, void *win, char **map);

#endif
