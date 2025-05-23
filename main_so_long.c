/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:01:13 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/23 18:43:42 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**open_read_maps(char *argv[])
{
	t_game	game;
	int		fd;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error, no se ha podido abrir el mapa\n",2);
		exit (1);
	}
	game.map = read_maps(fd);
	if (!game.map || !check_map(&game))
	{
		ft_putstr_fd("Error mapa\n", 2);
		free_map(game.map);
		exit (1);
	}
	close(fd);
	return (game.map);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	if (argc != 2)
	{
		ft_putstr_fd("Error, no se ha adjuntado mapa\n", 2);
		return (1);
	}
	game.map = open_read_maps(argv);
	init_window(&game);
	return (0);
}
