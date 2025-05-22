/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <mregada-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:01:13 by mregada-          #+#    #+#             */
/*   Updated: 2025/05/21 18:55:09 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
  int   fd;
  char  **map;

  if (argc != 2)
  {
    ft_putstr_fd("Error, no se ha adjuntado mapa\n", 2);
    return (1);
  }
  fd = open(argv[1], O_RDONLY);
  if (fd < 0)
  {
    ft_putstr_fd("Error, no se ha podido abrir el mapa\n",2);
    return (1);
  }
  map = read_maps(fd);
  if (!map || !check_map(map))
  {
    ft_putstr_fd("Error mapa\n", 2);
    free_map(map);
    return(1);
  }
	init_window(map);
  /* IMPRIMIR MAPA
	int i = 0;
  int j;
  while (map[i])
  {
    j = 0;
    while (map[i][j])
    {
      ft_printf("%c", map[i][j]);
      j++;
    }
    ft_printf("\n");
    i++;
  }*/
  close(fd);
  return (0);
}
