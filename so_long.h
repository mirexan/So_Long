/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:42:05 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/20 21:44:33 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define	SO_LONG_H

#	define TILE_SIZE 32
#	endif

#include "ft_printf/ft_printf.h"
#include "ft_getNextLine/get_next_line_bonus.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[]);
char	**read_maps(int fd);
void	free_map(char **map);
int	check_map(char **map);

#endif
