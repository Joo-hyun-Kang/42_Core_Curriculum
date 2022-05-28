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
	int	h;
	int	w;

	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			if (map->game_map->pa_arr[map->width * h + w] == '0')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->ground, w * 64, h * 64);
			else if (map->game_map->pa_arr[map->width * h + w] == '1')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->wall, w * 64, h * 64);
			else if (map->game_map->pa_arr[map->width * h + w] == 'C')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->ground, w * 64, h * 64);
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->item, w * 64, h * 64);
			}
			else if (map->game_map->pa_arr[map->width * h + w] == 'E')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->door, w * 64, h * 64);
			else if (map->game_map->pa_arr[map->width * h + w] == 'P')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->ground, w * 64, h * 64);
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image->player, w * 64, h * 64);
			}
			else
				ft_print_error();
			w++;
		}
		h++;
	}
}