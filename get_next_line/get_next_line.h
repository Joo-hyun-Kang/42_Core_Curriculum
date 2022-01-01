/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:40 by jokang            #+#    #+#             */
/*   Updated: 2021/12/16 17:08:33 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>

# define TRUE (1)
# define FALSE (0)

typedef struct
{
	char	*string_pa;
	size_t	capacity;
	void	*next;
}	t_table;

typedef struct
{
	char	*buffer_pa;
	int		is_EOF;
	size_t	num_count;
	size_t	last_count;
}	t_queue;

enum { e_TABLE_SIZE = 5 };

int		build_queue_malloc(t_queue **queue);
int		is_queue_empty(t_queue *queue_pa);
int		try_enqueue_fd(t_queue *queue_pa, int fd);
int		dequeue_by_next_line(t_queue *queue_pa, t_table *head);
char	*get_next_line(int fd);

void	*ft_memcpy(void *dst, const void *src, size_t n);
int     ft_read_str_fd(char* out_buffer, int fd, size_t len);
char    *ft_strdup_range_malloc(char *src, size_t start, size_t end);
int		add_back_table_malloc(t_table **head);
t_table	*build_table_malloc(void);
int		is_table_capacity_full(t_table *table);
char    *ft_strdup_table_malloc(t_table *head);
void	ft_lstclear(t_table **lst);

#endif /* GET_NEXT_LINE_H */



