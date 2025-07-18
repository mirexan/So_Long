/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:06:40 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/23 18:45:02 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_lines(char **map)
{
	int	lines;

	lines = 0;
	while (map[lines])
		lines++;
	return (lines);
}

void	init_window(t_game	*game)
{
	int			height;

	game->mlx = mlx_init(); //inicia conexion con sistema grafico y devuelve puntero
	if (!game->mlx)//de contexto
	{
		ft_putstr_fd("Error al iniciar mlx\n", 2);
		free_map(game->map);
		exit (1);
	}
	height = count_lines(game->map);
	game->win = mlx_new_window(game->mlx, ft_strlen(game->map[0])
			* TILE_SIZE, height * TILE_SIZE, "so_long");
	if (!game->win)//devuelve puntero que representa ventana
	{
		ft_putstr_fd("Error al abrir la ventana\n", 2);
		free_map(game->map);
		exit (1);
	}
	load_sprites(game);
	load_draw_map(game);
}
