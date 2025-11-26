/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:20:14 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/26 09:03:40 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*init_mlx(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		ft_printf("Initialisation of the minilibX failed !\n");
		exit (1);
	}
	return (mlx_ptr);
}

void	*display_window(void *mlx_ptr, int x, int y, char *name)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, x, y, name);
	if (!win_ptr)
	{
		ft_printf("Window display failed !\n");
		exit (1);
	}
	return (win_ptr);
}

int	close_window(void *param)
{
	t_thing	*game;

	game = (t_thing *)param;
	free_map (game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void	setup_hooks(t_thing *game)
{
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
}

int	keypress(int kc, void *param)
{
	t_thing	*game;

	game = (t_thing *)param;
	if (kc == 65307)
		close_window(game);
	if (kc == 119)
		movement(game, 0, -1);
	else if (kc == 97)
		movement(game, -1, 0);
	else if (kc == 115)
		movement(game, 0, 1);
	else if (kc == 100)
		movement(game, 1, 0);
	return (0);
}
