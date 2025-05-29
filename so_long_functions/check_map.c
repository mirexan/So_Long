/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:05:08 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/27 21:25:27 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_map_shape(t_game *game)
{
	int	i;
	int	len;

	if (!game->map || !game->map[0])
		return (0);
	len = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static void	count_elements(char c_map, int *p, int *e, int *c)
{
	if (c_map == 'P')
		(*p)++;
	else if (c_map == 'E')
		(*e)++;
	else if (c_map == 'C')
		(*c)++;
}

static int	check_map_elements(t_game *game)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = -1;
	p = 0;
	e = 0;
	c = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			count_elements(game->map[i][j], &p, &e, &c);
			if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
				game->player_dir = 0;
				game->map[i][j] = '0';
			}
		}
	}
	return (p == 1 && e == 1 && c >= 1);
}

static int	check_map_walls(t_game *game)
{
	int	i;
	int	height;
	int	width;

	height = 0;
	while (game->map[height])
		height++;
	width = ft_strlen(game->map[0]);
	i = 0;
	while (i < width)
	{
		if (game->map[0][i] != '1' || game->map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (game->map[i][0] != '1' || game->map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!check_map_shape(game))
	{
		ft_putstr_fd("Error en la forma del mapa\n", 2);
		return (0);
	}
	if (!check_map_elements(game))
	{
		ft_putstr_fd("Error en los elementos del mapa\n", 2);
		return (0);
	}
	if (!check_map_walls(game))
	{
		ft_putstr_fd("Error en los muros del mapa\n", 2);
		return (0);
	}
	return (1);
}
