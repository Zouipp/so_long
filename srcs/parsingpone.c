/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingpone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:17:38 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/19 16:57:18 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	map_check(nbr_entitys *etnt, const char *filename, cord *co, size *size)
{
	int			x;
	int			y;
	static char	**map;

	map = get_map(filename);
	y = -1;
	if (!is_rectangular(map))
		return (print_error("The map is not rectangular !"));
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!is_all_good(map[y][x], etnt))
				return (print_error("Unvalid char in map"));
		}
	}
	if	(etnt->ctE != 1 || etnt->ctC < 1 || etnt->ctP != 1)
		return (print_error("Wrong number of entitys"));
	if (!ft_is_surrounded(map))
		return (print_error("The map is not surrounded !"));
	get_coordinates(co, map);
	get_range(size, map);
	flood_fill(map, co, size, co->Px, co->Py);
	return (check_flood_fill(map));
}

int print_error(char *message)
{
	ft_printf("%s\n", message);
	return (0);
}

char **get_map(const char *filename)
{
	int		fd;
	char	*map;
	char	*line;
	char	**final;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	while ((line = get_next_line(fd)))
	{
		map = ft_strsuperjoin(map, line);
		free (line);
	}
	get_next_line(-1);
	close(fd);
	final =  ft_split((const char *)map, '\n');
	return (free (map), final);
}

int is_all_good(char c, nbr_entitys *entity)
{
	if ((c == '0') || (c == '1') || (c == 'C') || (c == 'E') || (c == 'P'))
	{
		if (c == 'E')
			entity->ctE++;
		if (c == 'P')
			entity->ctP++;
		if (c == 'C')
			entity->ctC++;
		return (1);
	}
	else
		return (0);
}

void flood_fill(char **map, cord *co, size *size, int x, int y)
{
	if (x < 0 || y < 0 || size->x <= x || size->y <= y)
		return ;
	if (map[y][x] == '1' || map[y][x] == '&')
		return ;
	map[y][x] = '&';
	flood_fill(map, co, size, (x - 1), y);
	flood_fill(map, co, size, x, (y - 1));
	flood_fill(map, co, size, (x + 1), y);
	flood_fill(map, co, size, x, (y + 1));
	return ;
}

// int main(void)
// {
//     nbr_entitys entity = {0};
// 	cord co = {0};
// 	size size = {0};
//     char filename[8] = "map.ber";
//     map_check(&entity, filename, &co, &size);
//     return (0);
// }