/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:01:13 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/27 21:55:42 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void open_read_maps(char *argv[], t_game *game)
{
	int		fd;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error, no se ha podido abrir el mapa\n",2);
		exit (1);
	}
	game->map = read_maps(fd);
	if (!game->map || !check_map(game))
	{
		ft_putstr_fd("Error mapa\n", 2);
		free_map(game->map);
		exit (1);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	if (argc != 2)
	{
		ft_putstr_fd("Error, no se ha adjuntado mapa\n", 2);
		return (1);
	}
	 open_read_maps(argv,&game);
	ft_printf("Dibujando jugador en x=%d, y=%d, dir=%d\n", game.player_x, game.player_y, game.player_dir);
	init_window(&game);
	mlx_key_hook(game.win, handle_key,&game);
	mlx_hook(game.win, 17, 0, handle_close,&game);
	mlx_loop(game.mlx);//Inicia bucle de eventos
	return (0);
}
