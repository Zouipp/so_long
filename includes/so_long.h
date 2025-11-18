/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:32:09 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/18 19:24:12 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct
{
	int ctE;
	int ctP;
	int ctC;
}nbr_entitys;

typedef struct 
{
	int Px;
	int Py;
	
	int Ex;
	int Ey;
}cord;

typedef struct 
{
	int x;
	int y;
}size;

typedef struct
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}t_game;


int		map_check(nbr_entitys *etnt, const char *filename, cord *co, size *size);
char	**get_map(const char *filename);
char    *ft_strsuperjoin(char *s1, char *s2);
int		is_all_good(char c, nbr_entitys *data);
int		print_error(char *message);
int		is_rectangular(char **map);
void	get_coordinates(cord *co, char **map);
void	get_range(size *size, char **map);
void	flood_fill(char **map, cord *co, size *size, int x, int y);
int		check_flood_fill(char **map);

# endif