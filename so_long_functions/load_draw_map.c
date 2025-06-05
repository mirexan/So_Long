/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:52:21 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/29 20:01:03 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*load_image(t_game *game, char *path)
{
	void	*img;
	int		h;
	int		w;
	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h); //de donde salen ha y w?
	if (!img)
	{
		ft_putstr_fd("Error al cargar: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		free_sprites(game);
		free_map(game->map);
		exit (1);
	}
	return (img);
}

void	load_sprites(t_game *game)
{
	game->sprites.floor = load_image(game, "./sprites/floor_64.xpm");
	game->sprites.wall = load_image(game, "./sprites/wall_64.xpm");
	game->sprites.collect = load_image(game, "./sprites/collect_64.xpm");
	game->sprites.exit = load_image(game, "./sprites/exit_64.xpm");
	game->sprites.player_up = load_image(game, "./sprites/Racoon_up.xpm");
	game->sprites.player_up_1 = load_image(game, "./sprites/Racoon_up_1.xpm");
	game->sprites.player = load_image(game, "./sprites/Racoon_64.xpm");
	game->sprites.player_1 = load_image(game, "./sprites/Racoon_64_1.xpm");
	game->sprites.player_left = load_image(game, "./sprites/Racoon_left.xpm");
	game->sprites.player_left_1 = load_image(
			game, "./sprites/Racoon_left_1.xpm");
	game->sprites.player_right = load_image(game, "./sprites/Racoon_right.xpm");
	game->sprites.player_right_1 = load_image(
			game, "./sprites/Racoon_right_1.xpm");
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.wall,j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.floor,j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.collect,j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.exit,j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	load_draw_map(t_game *game)
{
	draw_map(game);
	draw_player(game);
}
