/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:52:21 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/27 19:57:56 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*load_image(t_game *game, char *path)
{
	void	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img)
	{
		//ft_putstr_fd("Error al cargar imágenes\n", 2);
		ft_putstr_fd("Error al cargar: ", 2);
    	ft_putstr_fd(path, 2);
    	ft_putstr_fd("\n", 2);
		free_map(game->map);
		exit (1);
	}
	return (img);
}

static void	draw_player(t_game *game)
{
	int		x;
	int		y;
	void	*img;
	x = game->player_x * TILE_SIZE;
	y = game->player_y * TILE_SIZE;
	if (game->player_dir == 0)
		img = game->sprites.player;
	else if (game->player_dir == 1)
		img = game->sprites.player_up;
	else if (game->player_dir == 2)
		img = game->sprites.player_left;
	else
		img = game->sprites.player_right;
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

static void	load_sprites(t_game *game)
{
	game->sprites.background = load_image(game, "./sprites/back_64.xpm");
	game->sprites.floor = load_image(game, "./sprites/floor_64.xpm");
	game->sprites.wall = load_image(game, "./sprites/wall_64.xpm");
	game->sprites.collect = load_image(game, "./sprites/collect_64.xpm");
	game->sprites.exit = load_image(game, "./sprites/exit_64.xpm");
	game->sprites.player_up = load_image(game, "./sprites/Racoon_up.xpm");
	game->sprites.player = load_image(game, "./sprites/Racoon_64.xpm");
	game->sprites.player_left = load_image(game, "./sprites/Racoon_left.xpm");
	game->sprites.player_right = load_image(game, "./sprites/Racoon_right.xpm");
	//Poner background
}

void	draw_map(t_game *game)
{
	int	i;
	int j;
	
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall, 
					j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites.floor, 
					j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites.collect, 
					j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit, 
					j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	load_draw_map(t_game *game)
{	
	load_sprites(game);
	draw_map(game);
	draw_player(game);
}
