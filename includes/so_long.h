/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:32:09 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/26 08:50:03 by fbenech          ###   ########.fr       */
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
	int	ctE;
	int	ctP;
	int	ctC;
}nbr_entitys;

typedef struct 
{
	int		Px;
	int		Py;

	int		Ex;
	int		Ey;
	int		x;
	int		y;
	char	**map;
}cord;

typedef struct
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}t_game;

typedef struct
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit1;
	void	*img_exit2;
	char	**map;
	int		tile_size;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		count;
	int		footstep;
} t_thing;

int		map_check(nbr_entitys *etnt, const char *filename, cord *co);
char	**get_map(const char *filename);
char	*ft_strsuperjoin(char *s1, char *s2);
int		is_all_good(char c, nbr_entitys *data);
int		print_error(char *message);
int		is_rectangular(char **map);
char	**get_coordinates(cord *co, char **map);
char	**get_range(cord *size, char **map);
void	flood_fill(char **map, cord *co, int x, int y);
int		check_flood_fill(char **map);
int		ft_is_surrounded(char **map);
int		keypress(int kc, void *param);
void	setup_hooks(t_thing *game);
int		close_window(void *param);
void	*display_window(void *mlx_ptr, int x, int y, char *name);
void	*init_mlx(void);
void	load_texture(t_thing *game);
void	render_tile(char c, t_thing *game, int x, int y);
void	render_map(t_thing *game);
char	**get_map_copy(char **map);
void	movement(t_thing *game, int x, int y);
void	free_map(char **map);
void	init_game(t_thing *game, cord *co, nbr_entitys *entity);

# endif