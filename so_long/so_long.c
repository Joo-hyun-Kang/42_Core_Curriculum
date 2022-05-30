/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:57:08 by jokang            #+#    #+#             */
/*   Updated: 2022/05/30 15:58:11 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(void)
{
	write(1, "Error\n", 6);
	write(1, "Invaild Argument!\n", 18);
	exit(0);
}

void	ft_vaildate_argument(int argc, char **argv)
{
	char	*p;
	int		lenght;

	if (argc != 2)
		ft_print_error();
	p = argv[FIRST_ARG];
	lenght = ft_strlen(p);
	if (p[lenght - 4] != '.')
		ft_print_error();
	if (p[lenght - 3] != 'b')
		ft_print_error();
	if (p[lenght - 2] != 'e')
		ft_print_error();
	if (p[lenght - 1] != 'r')
		ft_print_error();
}

void	ft_free_game_resource(t_game *game)
{
	free_arraylist(game->pa_map->game_map);
	free(game->pa_map);
	free(game->pa_image);
	free(game->pa_play);
	free(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_vaildate_argument(argc, argv);
	game = (t_game *)malloc(sizeof(t_game));
	game->pa_map = (t_map *)malloc(sizeof(t_map));
	game->pa_image = (t_image *)malloc(sizeof(t_image));
	game->pa_play = (t_play *)malloc(sizeof(t_play));
	game->pa_play->item_count = 0;
	game->pa_play->step_count = 0;
	map_init_malloc(game->pa_map, argv[FIRST_ARG]);
	image_init(game->pa_map, game->pa_image);
	draw_map_to_image(game->pa_map, game->pa_image);
	mlx_hook(game->pa_map->win, KEY_EVENT, 0, &catch_move, game);
	mlx_hook(game->pa_map->win, DESTORY_EVENT, 0, &ft_end_game_press_x, game);
	mlx_loop(game->pa_map->mlx);
	ft_free_game_resource(game);
}
