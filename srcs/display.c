/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:20:14 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/18 20:52:05 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int display_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "So long");
	if (!game->win_ptr)
		return (0);
	mlx_loop(game->mlx_ptr);
	return (1);
}

int close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}