#include "so_long.h"

void	ft_printf_steps(t_game *g)
{
	g->pa_play->step_count++;
	printf("%d Steps\n", g->pa_play->step_count);
}

int	ft_end_game_press_x(t_game *g)
{
	mlx_destroy_window(g->pa_map->mlx_ptr, g->pa_map->win_ptr);
	exit(1);
}

void	ft_exit_game(t_game *g)
{
	ft_printf_steps(g);
	printf("GAME FINISHED GOOD BYE!\n");
	ft_free_game_resource(g);
	exit(1);
}

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
	else if (map[player_pos - g->pa_map->width] == 'E')
	{
		if (g->pa_play->item_count == g->pa_map->item_total)
			ft_exit_game(g);
	}
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
	else if (map[player_pos + g->pa_map->width] == 'E')
	{
		if (g->pa_play->item_count == g->pa_map->item_total)
			ft_exit_game(g);
	}
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
	else if (map[player_pos + 1] == 'E')
	{
		if (g->pa_play->item_count == g->pa_map->item_total)
			ft_exit_game(g);
	}
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
	else if (map[player_pos + -1] == 'E')
	{
		if (g->pa_play->item_count == g->pa_map->item_total)
			ft_exit_game(g);
	}
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
