/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:05:05 by jokang            #+#    #+#             */
/*   Updated: 2022/05/30 16:09:09 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft/libft.h"

# define FIRST_ARG (1)
# define FT_NULL (0)
# define TRUE (1)
# define FALSE (0)
# define BASIC_CAPACITY (10)

# define ESC_KEY (53)
# define W_KEY (13)
# define A_KEY (0)
# define D_KEY (2)
# define S_KEY (1)

# define KEY_EVENT (2)
# define DESTORY_EVENT (17)

typedef struct arraylist {
	char	*pa_arr;
	int		length;
	int		capacity;
}	t_arraylist;

typedef struct map
{
	t_arraylist	*game_map;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			item_total;
	int			player_total;
	int			exit_total;
	int			player_pos;
	int			is_square;
}	t_map;

typedef struct image
{
	void	*ground;
	void	*wall;
	void	*item;
	void	*door;
	void	*player;
}	t_image;

typedef struct ft_play
{
	int	step_count;
	int	item_count;
}	t_play;

typedef struct game
{
	t_map	*pa_map;
	t_image	*pa_image;
	t_play	*pa_play;
}	t_game;

enum e_DIR
{
	DIR_NORTH = W_KEY,
	DIR_WEST = A_KEY,
	DIR_SOUTH = S_KEY,
	DIR_EAST = D_KEY
};

typedef struct s_table
{
	char	*string_pa;
	size_t	capacity;
	void	*next;
}	t_table;

typedef struct s_queue
{
	char			*buffer_pa;
	int				is_eof;
	size_t			num_count;
	size_t			last_count;
	int				fd;
	struct s_queue	*next;
}	t_queue;

enum { e_size = 2048 };

/* GET_NEXT_LINE_BONUS.C */

t_queue		*set_queue_list(t_queue **queue, int fd);
void		free_t_struct(t_queue **queue, t_table **lst, int fd);
int			try_enqueue_fd(t_queue *queue_pa, int fd);
int			dequeue_by_next_line(t_queue *queue_pa, t_table *head);
char		*get_next_line(int fd);

void		*ft_memcpy(void *dst, const void *src, size_t n);
int			add_back_table_malloc(t_table **head);
t_table		*build_table_malloc(void);
int			is_table_capacity_full(t_table *table);
char		*ft_strdup_table_malloc(t_table *head);

/* ARRAYLIST.C */

int			add_arraylist(t_arraylist *arraylist, char value);
int			is_arraylist_full(t_arraylist *arraylist);
int			allocate_arraylist(t_arraylist *arraylist);
void		free_arraylist(t_arraylist *arraylist);
void		exit_malloc_fail(void *p);

/* SO_LONG.C */

void		ft_print_error(void);
void		ft_vaildate_argument(int argc, char **argv);
void		ft_free_game_resource(t_game *game);

/* MAP.C */
void		ft_copy_line(t_arraylist *list, char *src);
void		set_game_map(t_map *map, char *filename);
void		map_init_malloc(t_map *map, char *filename);
void		check_game_map(t_map *map);
void		check_game_map_helper(t_map *m, char *p, int h, int w);

/* IMAGE.C */

void		image_init(t_map *map, t_image *image);
void		draw_map_to_image(t_map *map, t_image *image);
void		draw_map_to_image_helper(t_map *m, t_image *i, int h, int w);

/* PLAY.C */

int			catch_move(int keycode, t_game *g);
void		ft_exit_game(t_game *g);
int			ft_end_game_press_x(t_game *g);
void		ft_printf_steps(t_game *g);

/* MOVE.C */

void		move_north(t_game *g);
void		move_south(t_game *g);
void		move_east(t_game *g);
void		move_west(t_game *g);

#endif /* SO_LONG_H */
