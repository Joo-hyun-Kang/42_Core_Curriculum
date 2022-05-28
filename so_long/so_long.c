#include "so_long.h"

# define FIRST_ARG (1)

void	ft_print_error()
{
	write(1, "Error\n", 6);
	exit(0);
}

int	map_init_malloc(t_map *map, char *filename)
{
	//파일명 에러 처리하기
	map->mlx_ptr = mlx_init();
	map->width = 0;
	map->height = 0;
	map->item_total = 0;
	map->player_total = 0;
	map->exit_total = 0;
	map->is_square = TRUE;

	map->game_map = (t_arraylist *)malloc(sizeof(t_arraylist));
	map->game_map->pa_arr = NULL;
	map->game_map->capacity = 0;
	map->game_map->length = 0;

	allocate_arraylist(map->game_map);
	
	set_game_map(map, filename);
	
	check_game_map(map);
	
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->width * 64, map->height * 64, "so long");
	
	return (0);
}

// 체크하기
int	check_game_map(t_map *m)
{
	char	*p;
	int		h;
	int		w;
	
	if (!m->is_square)
		ft_print_error();
	h = 0;
	p = m->game_map->pa_arr;
	while (h < m->height)
	{
		w = 0;
		while (w < m->width)
		{
			if (h == 0 && p[h * m->width + w] != '1')
				ft_print_error();
			if (h == m->height - 1 && p[h * m->width + w] != '1')
				ft_print_error();
			if (w == 0 && p[h * m->width + w] != '1')
				ft_print_error();
			if (w == m->width - 1 && p[h * m->width + w] != '1')
				ft_print_error();
			if (p[h * m->width + w] == 'E')
				m->exit_total++;
			else if (p[h * m->width + w] == 'C')
				m->item_total++;
			else if (p[h * m->width + w] == 'P')
			{
				m->player_total++;
				m->player_pos = h * m->width + w;
			}
			w++;
		}
		h++;
	}
	if (m->exit_total == 0 || m->player_total != 1 || m->item_total == 0)
			ft_print_error();
	return (0);
}

void	set_game_map(t_map *map, char *filename)
{
	char	*pa_line;
	int		fd;
	int		prev_width;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(0);
	pa_line = get_next_line(fd);
	prev_width = ft_strlen(pa_line) - 1;
	map->height++;
	ft_copy_line(map->game_map, pa_line);
	free(pa_line);
	pa_line = get_next_line(fd);
	while (pa_line != NULL)
	{
		map->width = ft_strlen(pa_line) - 1;
		if (prev_width != map->width)
			map->is_square = FALSE;
		map->height++;
		ft_copy_line(map->game_map, pa_line);
		free(pa_line);
		pa_line = get_next_line(fd);
	}
	close(fd);
}

void	ft_copy_line(t_arraylist *list, char *src)
{
	while (*src != '\n')
	{
		add_arraylist(list, *src);
		src++;
	}
}

int main(int argc, char **argv)
{
	t_game	*game;
	/*
	{
		void	*mlx_ptr;
		void	*win_ptr;

		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
		mlx_loop(mlx_ptr);
	}
	*/
	// 예외처리 ㄱㄱ
	game = (t_game *)malloc(sizeof(t_game));
	game->pa_map = (t_map *)malloc(sizeof(t_map));
	game->pa_image = (t_image *)malloc(sizeof(t_image));
	game->pa_play = (t_play *)malloc(sizeof(t_play));
	game->pa_play->item_count = 0;
	game->pa_play->step_count = 0;
	map_init_malloc(game->pa_map, argv[FIRST_ARG]);

	image_init(game->pa_map, game->pa_image);

	draw_map_to_image(game->pa_map, game->pa_image);
 
	mlx_key_hook(game->pa_map->win_ptr, &catch_move, game);

	mlx_loop(game->pa_map->mlx_ptr);
	//free ㄱㄱ
	//free(arraylist)
	//free(map)
	//free(image)
	//free(play)
	//free(game)
}