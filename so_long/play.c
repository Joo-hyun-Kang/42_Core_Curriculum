/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:43:22 by jokang            #+#    #+#             */
/*   Updated: 2022/05/30 16:09:14 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printf_steps(t_game *g)
{
	g->pa_play->step_count++;
	printf("%d Steps\n", g->pa_play->step_count);
}

int	ft_end_game_press_x(t_game *g)
{
	mlx_destroy_window(g->pa_map->mlx, g->pa_map->win);
	exit(1);
}

void	ft_exit_game(t_game *g)
{
	ft_printf_steps(g);
	printf("GAME FINISHED GOOD BYE!\n");
	ft_free_game_resource(g);
	exit(1);
}

int	catch_move(int keycode, t_game *g)
{
	if (keycode == W_KEY)
		move_north(g);
	else if (keycode == A_KEY)
		move_west(g);
	else if (keycode == S_KEY)
		move_south(g);
	else if (keycode == D_KEY)
		move_east(g);
	else if (keycode == ESC_KEY)
		ft_exit_game(g);
	return (0);
}
