/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:52:21 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/22 19:27:34 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*load_image(void *mlx, char *path)
{
	void	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!img)
	{
		ft_putstr_fd("Error al cargar imágenes\n", 2);
		free_map(map);
		exit (1);
	}
	return (img);
}

t_sprites	load_sprites(void *mlx)
{
	t_sprites	sprites;

	sprites.background = load_image(mlx, "./sprites/back_32.xpm");
	sprites.floor = load_image(mlx, "./sprites/floor_32.xpm");
	sprites.wall = load_image(mlx, "./sprites/wall_32.xpm");
	sprites.collect = load_image(mlx, "./sprites/collect_32.xpm");
	sprites.exit = load_image(mlx, "./sprites/exit_32.xpm");
	sprites.player = load_images(mlx, "./sprites/Raccon_32.xpm");
	return (sprites);
}



void	load_draw_map(void *mlx, void *win, char **map)
{
	t_sprites	sprites;
	
	sprites = load_sprites(mlx);
	draw_map(mlx, win, map, sprites);
}
