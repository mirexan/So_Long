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
static void	init_game_var(t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->player_dir = 0;
	game->move_count = 0;
	game->player_moving = 0;
	game->collected = 0;
	/*game->sprites.floor = NULL;
	game->sprites.wall = NULL;
	game->sprites.collect = NULL;
	game->sprites.exit = NULL;
	game->sprites.player = NULL;
	game->sprites.player_up = NULL;
	game->sprites.player_left = NULL;
	game->sprites.player_right = NULL;
	game->sprites.player_1 = NULL;
	game->sprites.player_up_1 = NULL;
	game->sprites.player_left_1 = NULL;
	game->sprites.player_right_1 = NULL;*/
}

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
	init_game_var(&game);
	open_read_maps(argv,&game);
	init_window(&game);
	mlx_key_hook(game.win, handle_key,&game);
	mlx_hook(game.win, 17, 0, handle_close,&game);
	mlx_loop(game.mlx);//Inicia bucle de eventos
	return (0);
}
