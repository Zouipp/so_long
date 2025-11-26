/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:22:02 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/25 09:57:52 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_texture(t_thing *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/img_hole.xpm",
			&width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/img_collectible.xpm", &width, &height);
	game->img_exit1 = mlx_xpm_file_to_image(game->mlx,
			"assets/exit_damage.xpm", &width, &height);
	game->img_exit2 = mlx_xpm_file_to_image(game->mlx,
			"assets/img_exit.xpm", &width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/img_player.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/img_floor.xpm", &width, &height);
	game->tile_size = width;
}

void	render_tile(char c, t_thing *game, int x, int y)
{
	void	*img;

	if (c == '1')
		img = game->img_wall;
	else if (c == 'C')
		img = game->img_collectible;
	else if (c == 'P')
		img = game->img_player;
	else if (c == 'E')
	{
		if (game->count == 0)
			img = game->img_exit2;
		else
			img = game->img_exit1;
	}
	else
		return ;
	mlx_put_image_to_window (game->mlx, game->win, img, x * game->tile_size,
		y * game->tile_size);
}

void	render_map(t_thing *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				x * game->tile_size, y * game->tile_size);
			if (game->map[y][x] != '0')
				render_tile(game->map[y][x], game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
