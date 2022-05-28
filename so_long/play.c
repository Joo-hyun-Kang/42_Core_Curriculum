#include "so_long.h"

void	ft_exit_game()
{
	exit(1);
}

void	move_north(t_game *g)
{
	char	*map;
	int		player_pos;

	player_pos = g->pa_map->player_pos;
	map = g->pa_map->game_map->pa_arr;
	//대지일 때
	if (map[player_pos - g->pa_map->width] == '0')
	{
		map[player_pos - g->pa_map->width] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos - g->pa_map->width;
		draw_map_to_image(g->pa_map, g->pa_image);
	} //아이템일 때
	else if (map[player_pos - g->pa_map->width] == 'C')
	{
		g->pa_play->item_count++;
		map[player_pos - g->pa_map->width] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos - g->pa_map->width;
		draw_map_to_image(g->pa_map, g->pa_image);
	} 
	else if (map[player_pos - g->pa_map->width] == 'E')
	{
		if (g->pa_play->item_count == g->pa_map->item_total)
			ft_exit_game();
	}
}

void	move_south(t_game *g)
{
	char	*map;
	int		player_pos;

	player_pos = g->pa_map->player_pos;
	map = g->pa_map->game_map->pa_arr;
	//대지일 때
	if (map[player_pos + g->pa_map->width] == '0')
	{
		map[player_pos + g->pa_map->width] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + g->pa_map->width;
		draw_map_to_image(g->pa_map, g->pa_image);
	} //아이템일 때
	else if (map[player_pos + g->pa_map->width] == 'C')
	{
		g->pa_play->item_count++;
		map[player_pos + g->pa_map->width] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + g->pa_map->width;
		draw_map_to_image(g->pa_map, g->pa_image);
	} 
	else if (map[player_pos + g->pa_map->width] == 'E')
	{
		if (g->pa_play->item_count == g->pa_map->item_total)
			ft_exit_game();
	}
}

void	move_east(t_game *g)
{
	char	*map;
	int		player_pos;

	player_pos = g->pa_map->player_pos;
	map = g->pa_map->game_map->pa_arr;
	//대지일 때
	if (map[player_pos + 1] == '0')
	{
		map[player_pos + 1] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + 1;
		draw_map_to_image(g->pa_map, g->pa_image);
	} //아이템일 때
	else if (map[player_pos + 1] == 'C')
	{
		g->pa_play->item_count++;
		map[player_pos + 1] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + 1;
		draw_map_to_image(g->pa_map, g->pa_image);
	} 
	else if (map[player_pos + 1] == 'E')
	{
		if (g->pa_play->item_count == g->pa_map->item_total)
			ft_exit_game();
	}
}

void	move_west(t_game *g)
{
	char	*map;
	int		player_pos;

	player_pos = g->pa_map->player_pos;
	map = g->pa_map->game_map->pa_arr;
	//대지일 때
	if (map[player_pos + -1] == '0')
	{
		map[player_pos + -1] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + -1;
		draw_map_to_image(g->pa_map, g->pa_image);
	} //아이템일 때
	else if (map[player_pos + -1] == 'C')
	{
		g->pa_play->item_count++;
		map[player_pos + -1] = 'P';
		map[player_pos] = '0';
		g->pa_map->player_pos = player_pos + -1;
		draw_map_to_image(g->pa_map, g->pa_image);
	} 
	else if (map[player_pos + -1] == 'E')
	{
		if (g->pa_play->item_count == g->pa_map->item_total)
			ft_exit_game();
	}
}

int	catch_move(int keycode, t_game *g)
{
	
	/*
	if (keycode == DIR_NORTH)
		move_north(g);
	return 0;

	*/
	if (keycode == W_KEY)
		move_north(g);
	if (keycode == A_KEY)
		move_west(g);
	if (keycode == S_KEY)
		move_south(g);
	if (keycode == D_KEY)
		move_east(g);
	return (0);
}
