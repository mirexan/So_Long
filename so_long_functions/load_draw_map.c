/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:52:21 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/22 22:13:18 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*load_image(void *mlx, char *path, char **map)
{
	void	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!img)
	{
		//ft_putstr_fd("Error al cargar imágenes\n", 2);
		ft_putstr_fd("Error al cargar: ", 2);
    	ft_putstr_fd(path, 2);
    	ft_putstr_fd("\n", 2);
		free_map(map);
		exit (1);
	}
	return (img);
}

static t_sprites	load_sprites(void *mlx, char **map)
{
	t_sprites	sprites;

	sprites.background = load_image(mlx, "./sprites/back_64.xpm", map);
	sprites.floor = load_image(mlx, "./sprites/floor_64.xpm", map);
	sprites.wall = load_image(mlx, "./sprites/wall_64.xpm", map);
	sprites.collect = load_image(mlx, "./sprites/collect_64.xpm", map);
	sprites.exit = load_image(mlx, "./sprites/exit_64.xpm", map);
	//sprites.player_up = load_image(mlx, "./sprites/Racoon_up.xpm", map);
	sprites.player = load_image(mlx, "./sprites/Racoon_64.xpm", map);
	/*sprites.player_left = load_image(mlx, "./sprites/Racoon_left.xpm", map);
	sprites.player_right = load_image(mlx, "./sprites/Racoon_right.xpm", map);*/
	//Poner movimiento cuando haya avanzado
	return (sprites);
}

void	draw_map(void *mlx, void *win, char **map, t_sprites sprites)
{
	int	i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, sprites.wall, j * TILE_SIZE, 
				i * TILE_SIZE);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, sprites.floor, j * TILE_SIZE, 
				i * TILE_SIZE);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, sprites.collect, j * TILE_SIZE, 
				i * TILE_SIZE);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, sprites.exit, j * TILE_SIZE, 
				i * TILE_SIZE);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, sprites.player, j * TILE_SIZE, 
				i * TILE_SIZE);
			else
				mlx_put_image_to_window(mlx, win, sprites.background, j * TILE_SIZE, 
				i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	load_draw_map(void *mlx, void *win, char **map)
{
	t_sprites	sprites;
	
	sprites = load_sprites(mlx, map);
	draw_map(mlx, win, map, sprites);
}
