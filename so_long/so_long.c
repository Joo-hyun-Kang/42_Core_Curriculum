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

int	check_game_map(t_map *map)
{
	// 지도가 직사각형인지 체크
	
	// ***** 5
	// ****** 6
	// **** 4
	//
	// 5 * 3 = 15
	// 

	// 지도가 벽으로 둘러쌓였는 지 체크

	// 맵에 출구 / 시작 지점 / 수집품이 없는 경우
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
	prev_width = 0;
	pa_line = get_next_line(fd);
	while (pa_line != NULL)
	{
		map->width = ft_strlen(pa_line) - 1;
		// 최초의 이전 값은 0인데 일단 이건 넘어거야 함
		// 0인 것보다 크면 넘어감
		if (map->width > prev_width)
		{
			
		}
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
	t_game	game;
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
	map_init_malloc(&game.map, argv[FIRST_ARG]);

	image_init(&game.map, &game.image);

	draw_map_to_image(&game.map, &game.image);
 
	mlx_key_hook(game.map.mlx_ptr, catch_move, &game);

	mlx_loop(game.map.mlx_ptr);
	//free ㄱㄱ
	//free(map)
	//free(arraylist)
}