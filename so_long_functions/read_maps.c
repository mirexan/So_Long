
#include "../so_long.h"

void free_map(char **map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

static char	**allocate_tmp(char **map, int read_lines, char *line)
{
	char	**tmp;
	int	i;

	i = 0;//reserva espacio para una línea de más y un NULL final
	tmp = malloc(sizeof(char *) * (read_lines + 2));
	if (!tmp)
		return (NULL);
	while (i < read_lines)
	{
		//copia líneas leídas en el nuevo array
		tmp[i] = map[i]; //se añade a tmp para copiar
		i++;
	}
	tmp[read_lines] = line; //se añade la nueva línea al final
	tmp[read_lines + 1] = NULL; //y se añade NULL
	return(tmp);
}
static char	*clean_line(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

char **read_maps(int fd)
{
	char	*line;
	char	**map;
	char	**tmp;
	int		read_lines;

	map = NULL;
	read_lines = 0;
	line = clean_line(get_next_line(fd));//sacar linea quitando \n
	while (line)
	{
		tmp = allocate_tmp(map, read_lines, line);
		if (!tmp)
		{
			free(line);
			free_map(map);
			return(NULL);
		}
		free(map);//liberamos array viejo para
		map = tmp;//poder actualizar con el nuevo
		read_lines++;//sumar contador de lineas
		line = clean_line(get_next_line(fd));//leer la siguiente linea quitando \n
	}
	return (map);
}