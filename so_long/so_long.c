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
	//map->win_ptr = mlx_new_window(map->mlx_ptr, 500, 500, "jokang's Game");
	map->width = 0;
	map->height = 0;
	map->game_map = (t_arraylist *)malloc(sizeof(t_arraylist));
	allocate_arraylist(map->game_map);
	set_game_map(map, filename);
	check_game_map(map);
	return (0);
}

int	check_game_map(t_map *map)
{
	// 지도가 직사각형인지 체크

	// 지도가 벽으로 둘러쌓였는 지 체크

	// 맵에 출구 / 시작 지점 / 수집품이 없는 경우
	return (0);
}

void	set_game_map(t_map *map, char *filename)
{
	char	*pa_line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(0);
	pa_line = get_next_line(fd);
	while (pa_line != NULL)
	{
		map->width = ft_strlen(pa_line) - 1;
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
	t_map	map;
	t_image	image;
	
	// 예외처리 ㄱㄱ

	map_init_malloc(&map, argv[FIRST_ARG]);
	printf("error\n");
	
	//image_init(&map, &image);


	//free ㄱㄱ
	//free(map)
	//free(arraylist)
}