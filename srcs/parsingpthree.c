/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingpthree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:59:05 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/25 10:00:51 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map_copy(char **map)
{
	char	**tmp;
	int		y;
	int		x;

	y = 0;
	while (map[y])
		y++;
	tmp = malloc(sizeof(char *) * (y + 1));
	if (!tmp)
		return (NULL);
	y = 0;
	while (map[y])
	{
		x = 0;
		tmp[y] = malloc(sizeof(char) * (ft_strlen(map[y]) + 1));
		while (map[y][x])
		{
			tmp[y][x] = map[y][x];
			x++;
		}
		tmp[y][x] = '\0';
		y++;
	}
	tmp[y] = NULL;
	return (tmp);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
