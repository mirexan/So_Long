#include "../so_long.h"

static int	check_map_shape(char **map)
{
	int i, len;

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

static int check_map_elements(char **map)
{
	int i, j;
	int p, e, c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while ( map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (p == 1 && e == 1 && c >= 1);
}

static int check_map_walls(char **map)
{
	int i;
	int	height, width;

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
			return(0);
		i++;
	}
	return (1);
}

int	check_map(char **map)
{
	if (!check_map_shape(map))
	{
		ft_putstr_fd("Error en la forma del mapa\n",2);
		return (0);
	}
	if (!check_map_elements(map))
	{
		ft_putstr_fd("Error en los elementos del mapa\n",2);
		return (0);
	}

	if (!check_map_walls(map))
	{
		ft_putstr_fd("Error en los muros del mapa\n",2);
		return (0);
	}
		return (1);
}