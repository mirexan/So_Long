/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reachable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:57:35 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/29 21:57:37 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**copy_map(char **map)
{
	char	**copy;
	int	i;
	
	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **copied_map, int y, int x, t_game *game)
{//empieza desde posicion player
	if (copied_map[y][x] == '1' || copied_map[y][x] == 'V')
		return;//si es muro o ya se visito salimos recursion
	if (copied_map[y][x] == 'C')
		game->reachable_collect++;
	if (copied_map[y][x] == 'E')
		game->exit_reachable = 1;
	copied_map[y][x] = 'V';
	flood_fill(copied_map, y + 1, x, game);
	flood_fill(copied_map, y - 1, x, game);
	flood_fill(copied_map, y, x + 1, game);
	flood_fill(copied_map, y, x - 1, game);
}

int	is_reachable(t_game *game)
{
	char	**copied_map;//hacemos una copia del mapa para no modificar el
//original con flood fill
	copied_map = NULL;
	copied_map = copy_map(game->map);
	if (!copied_map)
		return (0);
	flood_fill(copied_map, game->player_y, game->player_x, game);
	free(copied_map);
	return (game->reachable_collect == game->total_collect &&
	 game->exit_reachable);
}
