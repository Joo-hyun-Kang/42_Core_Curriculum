/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:52:56 by jokang            #+#    #+#             */
/*   Updated: 2022/05/30 16:04:42 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init_malloc(t_map *m, char *filename)
{
	m->mlx = mlx_init();
	m->width = 0;
	m->height = 0;
	m->item_total = 0;
	m->player_total = 0;
	m->exit_total = 0;
	m->is_square = TRUE;
	m->game_map = (t_arraylist *)malloc(sizeof(t_arraylist));
	m->game_map->pa_arr = FT_NULL;
	m->game_map->capacity = 0;
	m->game_map->length = 0;
	allocate_arraylist(m->game_map);
	set_game_map(m, filename);
	check_game_map(m);
	m->win = mlx_new_window(m->mlx, m->width * 64, m->height * 64, "so long");
}

void	check_game_map(t_map *m)
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
			check_game_map_helper(m, p, h, w);
			w++;
		}
		h++;
	}
	if (m->exit_total == 0 || m->player_total != 1 || m->item_total == 0)
		ft_print_error();
}

void	check_game_map_helper(t_map *m, char *p, int h, int w)
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
}

void	set_game_map(t_map *map, char *filename)
{
	char	*pa_line;
	int		fd;
	int		prev_width;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_print_error();
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
