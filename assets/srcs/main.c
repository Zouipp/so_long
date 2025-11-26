/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:46:19 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/26 09:03:30 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_game(t_thing *game, cord *co, nbr_entitys *entity)
{
	game->map = co->map;
	game->p_x = co->Px;
	game->p_y = co->Py;
	game->count = entity->ctC;
	game->width = co->x;
	game->height = co->y;
	game->footstep = 0;
}
int	main(int ac, char **av)
{
	t_thing		game;
	nbr_entitys	entity;
	cord		co;
	int			win_width;
	int			win_height;

	entity = (nbr_entitys){0};
	co = (cord){0};
	if (ac != 2)
		return (print_error("Unvalid input"));
	map_check(&entity, av[1], &co);
	if (!co.map)
		return (0);
	init_game(&game, &co, &entity);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (print_error("mlx_init failed !"));
	load_texture(&game);
	win_width = co.x * game.tile_size;
	win_height = co.y * game.tile_size;
	game.win = display_window(game.mlx, win_width, win_height, "So_long");
	render_map(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
