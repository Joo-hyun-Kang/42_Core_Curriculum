/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:48:36 by jokang            #+#    #+#             */
/*   Updated: 2022/05/30 15:51:26 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_north(t_game *g)
{
	char	*map;
	int		player_pos;

	player_pos = g->pa_map->player_pos;
	map = g->pa_map->game_map->pa_arr;
	if (map[player_pos - g->pa_map->width] == '0')
	{
		map[player_pos - g->pa_map->width] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos - g->pa_map->width;
		ft_printf_steps(g);
		draw_map_to_image(g->pa_map, g->pa_image);
	}
	else if (map[player_pos - g->pa_map->width] == 'C')
	{
		g->pa_play->item_count++;
		map[player_pos - g->pa_map->width] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos - g->pa_map->width;
		ft_printf_steps(g);
		draw_map_to_image(g->pa_map, g->pa_image);
	}
	else if ((map[player_pos - g->pa_map->width] == 'E') \
	&& (g->pa_play->item_count == g->pa_map->item_total))
		ft_exit_game(g);
}

void	move_south(t_game *g)
{
	char	*map;
	int		player_pos;

	player_pos = g->pa_map->player_pos;
	map = g->pa_map->game_map->pa_arr;
	if (map[player_pos + g->pa_map->width] == '0')
	{
		map[player_pos + g->pa_map->width] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + g->pa_map->width;
		ft_printf_steps(g);
		draw_map_to_image(g->pa_map, g->pa_image);
	}
	else if (map[player_pos + g->pa_map->width] == 'C')
	{
		g->pa_play->item_count++;
		map[player_pos + g->pa_map->width] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + g->pa_map->width;
		ft_printf_steps(g);
		draw_map_to_image(g->pa_map, g->pa_image);
	}
	else if ((map[player_pos + g->pa_map->width] == 'E') \
	&& (g->pa_play->item_count == g->pa_map->item_total))
		ft_exit_game(g);
}

void	move_east(t_game *g)
{
	char	*map;
	int		player_pos;

	player_pos = g->pa_map->player_pos;
	map = g->pa_map->game_map->pa_arr;
	if (map[player_pos + 1] == '0')
	{
		map[player_pos + 1] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + 1;
		ft_printf_steps(g);
		draw_map_to_image(g->pa_map, g->pa_image);
	}
	else if (map[player_pos + 1] == 'C')
	{
		g->pa_play->item_count++;
		map[player_pos + 1] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + 1;
		ft_printf_steps(g);
		draw_map_to_image(g->pa_map, g->pa_image);
	}
	else if ((map[player_pos + 1] == 'E') \
	&& (g->pa_play->item_count == g->pa_map->item_total))
		ft_exit_game(g);
}

void	move_west(t_game *g)
{
	char	*map;
	int		player_pos;

	player_pos = g->pa_map->player_pos;
	map = g->pa_map->game_map->pa_arr;
	if (map[player_pos + -1] == '0')
	{
		map[player_pos + -1] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + -1;
		ft_printf_steps(g);
		draw_map_to_image(g->pa_map, g->pa_image);
	}
	else if (map[player_pos + -1] == 'C')
	{
		g->pa_play->item_count++;
		map[player_pos + -1] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + -1;
		ft_printf_steps(g);
		draw_map_to_image(g->pa_map, g->pa_image);
	}
	else if ((map[player_pos + -1] == 'E') \
	&& (g->pa_play->item_count == g->pa_map->item_total))
		ft_exit_game(g);
}
