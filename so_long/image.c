/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:30:12 by jokang            #+#    #+#             */
/*   Updated: 2022/05/30 16:13:15 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_init(t_map *map, t_image *im)
{
	int	w;
	int	h;

	im->ground = mlx_xpm_file_to_image(map->mlx, "./img/back.xpm", &w, &h);
	im->wall = mlx_xpm_file_to_image(map->mlx, "./img/obs.xpm", &w, &h);
	im->item = mlx_xpm_file_to_image(map->mlx, "./img/point.xpm", &w, &h);
	im->door = mlx_xpm_file_to_image(map->mlx, "./img/goal.xpm", &w, &h);
	im->player = mlx_xpm_file_to_image(map->mlx, "./img/play.xpm", &w, &h);
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
			draw_map_to_image_helper(map, image, h, w);
			w++;
		}
		h++;
	}
}

void	draw_map_to_image_helper(t_map *m, t_image *i, int h, int w)
{
	if (m->game_map->pa_arr[m->width * h + w] == '0')
		mlx_put_image_to_window(m->mlx, m->win, i->ground, w * 64, h * 64);
	else if (m->game_map->pa_arr[m->width * h + w] == '1')
		mlx_put_image_to_window(m->mlx, m->win, i->wall, w * 64, h * 64);
	else if (m->game_map->pa_arr[m->width * h + w] == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->win, i->ground, w * 64, h * 64);
		mlx_put_image_to_window(m->mlx, m->win, i->item, w * 64, h * 64);
	}
	else if (m->game_map->pa_arr[m->width * h + w] == 'E')
		mlx_put_image_to_window(m->mlx, m->win, i->door, w * 64, h * 64);
	else if (m->game_map->pa_arr[m->width * h + w] == 'P')
	{
		mlx_put_image_to_window(m->mlx, m->win, i->ground, w * 64, h * 64);
		mlx_put_image_to_window(m->mlx, m->win, i->player, w * 64, h * 64);
	}
	else
		ft_print_error();
}
