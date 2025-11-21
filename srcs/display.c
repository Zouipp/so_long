/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:20:14 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/19 17:52:32 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void *init_mlx(void)
{
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		ft_printf("Initialisation of the minilibX failed !\n");
		exit (1);
	}
	return (mlx_ptr);
}

void *display_window(void *mlx_ptr, int x, int y, char *name)
{
	void *win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, x, y, name);
	if (!win_ptr)
	{
		ft_printf("Window display failed !\n");
		exit (1);
	}
	return (win_ptr);
}

int close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void setup_hooks(void *win_ptr)
{
	mlx_hook(win_ptr, 17, 0, close_window, NULL);
	mlx_hook(win_ptr, 2, 1L<<0, keypress, NULL);
}

int keypress(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
	exit (0);
	return (0);
}
int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = init_mlx();
	win_ptr = display_window(mlx_ptr, 800, 600, "So_long");
	setup_hooks(win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}