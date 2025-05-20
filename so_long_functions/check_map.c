/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:05:08 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/20 22:33:03 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_map_shape(char **map)
{
	int	i;
	int	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
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

static int	check_map_elements(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			count_elements(map[i][j++], &p, &e, &c);
		i++;
	}
	return (p == 1 && e == 1 && c >= 1);
}

static int	check_map_walls(char **map)
{
	int	i;
	int	height;
	int	width;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(char **map)
{
	if (!check_map_shape(map))
	{
		ft_putstr_fd("Error en la forma del mapa\n", 2);
		return (0);
	}
	if (!check_map_elements(map))
	{
		ft_putstr_fd("Error en los elementos del mapa\n", 2);
		return (0);
	}
	if (!check_map_walls(map))
	{
		ft_putstr_fd("Error en los muros del mapa\n", 2);
		return (0);
	}
	return (1);
}
