/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 05:23:27 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/26 09:03:52 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_player_position(t_thing *game, int newx, int newy)
{
	game->map[game->p_y][game->p_x] = '0';
	game->map[newy][newx] = 'P';
	game->p_y = newy;
	game->p_x = newx;
	game->footstep++;
	render_map(game);
	ft_printf("%d\n", game->footstep);
}

static int	handle_tile(t_thing *game, int newx, int newy)
{
	if (game->map[newy][newx] == 'C')
		game->count--;
	if (game->map[newy][newx] == 'E')
	{
		if (game->count == 0)
		{
			ft_printf("YOU TOOK OFF !\n");
			exit(0);
		}
		return (0);
	}
	return (1);
}

static int	is_valid_move(t_thing *game, int newx, int newy)
{
	if (newy <= 0 || newy >= game->height)
		return (0);
	if (newx <= 0 || newx >= game->width)
		return (0);
	if (game->map[newy][newx] == '1')
		return (0);
	return (1);
}

void	movement(t_thing *game, int x, int y)
{
	int	newx;
	int	newy;

	newx = game->p_x + x;
	newy = game->p_y + y;
	if (!is_valid_move(game, newx, newy))
		return ;
	if (!handle_tile(game, newx, newy))
		return ;
	update_player_position(game, newx, newy);
}

