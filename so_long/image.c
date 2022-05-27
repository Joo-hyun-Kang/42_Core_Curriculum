#include "so_long.h"

void	image_init(t_map *map, t_image *image)
{
	int	width;
	int	height;

	image->ground = mlx_xpm_file_to_image(map->mlx_ptr, "./images/back.xpm", &width, &height);
	image->wall = mlx_xpm_file_to_image(map->mlx_ptr, "./images/obs.xpm", &width, &height);
	image->item = mlx_xpm_file_to_image(map->mlx_ptr, "./images/point.xpm", &width, &height);
	image->door = mlx_xpm_file_to_image(map->mlx_ptr, "./images/goal.xpm", &width, &height);
	image->player = mlx_xpm_file_to_image(map->mlx_ptr, "./images/play.xpm", &width, &height);
}

void	draw_map_to_image(t_map *map, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->game_map->pa_arr[map->width * i + j] == '0')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->ground, i, j);
			else if (map->game_map->pa_arr[map->width * i + j] == '1')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->wall, i, j);
			else if (map->game_map->pa_arr[map->width * i + j] == 'C')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->item, i, j);
			else if (map->game_map->pa_arr[map->width * i + j] == 'E')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->door, i, j);
			else if (map->game_map->pa_arr[map->width * i + j] == 'P')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->door, i, j);
			else
				ft_print_error();
			j++;
			// 0000
			// 0000
			// 0123
			// 4567
		}
		i++;
	}
}