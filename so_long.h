/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:42:05 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/27 20:10:56 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# include "ft_printf/ft_printf.h"
# include "ft_getNextLine/get_next_line_bonus.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_sprites
{
	void	*floor;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
	void	*player_1;
	void	*player_up;
	void	*player_up_1;
	void	*player_left;
	void	*player_left_1;
	void	*player_right;
	void	*player_right_1;
}	t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			player_x;
	int			player_y;
	int			player_dir;
	int			player_moving;
	int			move_count;
	int			collected;
	int			total_collect;
	int			reachable_collect;
	int			exit_reachable;
	t_sprites	sprites;
}	t_game;

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
void	draw_player(t_game *game);
int		is_reachable(t_game *game);
void	free_sprites(t_game *game);
void	load_sprites(t_game *game);
void	*load_image(t_game *game, char *path);
char	*ft_strrchr(const char *str, int c);
int	ft_strncmp(const char *s1, const char *s2);

#endif
