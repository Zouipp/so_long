/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingptwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:59:31 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/18 20:44:45 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	is_rectangular(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) == ft_strlen(map[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}

void get_coordinates(cord *co, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while(map[y][x])
		{
			if(map[y][x] == 'P')
			{
				co->Px = x;
				co->Py = y;
			}
			if (map[y][x] == 'E')
			{
				co->Ex = x;
				co->Ey = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void get_range(size *size, char **map)
{
	size->y = 0;
	size->x = ft_strlen(map[size->y]);;
	
	while(map[size->y + 1])
		size->y++;
}

int	check_flood_fill(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return(print_error("Unvalid path !"));
			x++;
		}
		x = 0;
		y++;
	}
	ft_printf("The map is valid !\n");
	return (1);
}