/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:06:40 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/22 18:55:13 by mregada-         ###   ########.fr       */
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

void	init_window(char **map)
{
	void		*mlx;
	void		*win;
	int			height;

	mlx = mlx_init(); //inicia conexion con sistema grafico y devuelve puntero
	if (!mlx)//de contexto
	{
		ft_putstr_fd("Error al iniciar mlx\n", 2);
		free_map(map);
		exit (1);
	}
	height = count_lines(map);
	win = mlx_new_window(mlx, ft_strlen(map[0]) * TILE_SIZE,
			height * TILE_SIZE, "so_long");
	if (!win)//devuelve puntero que representa ventana
	{
		ft_putstr_fd("Error al abrir la ventana\n", 2);
		free_map(map);
		exit (1);
	}
	load_draw_map(mlx, win, map);
	mlx_loop(mlx);//Inicia bucle de eventos
}
