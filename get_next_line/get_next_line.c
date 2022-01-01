/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:10:11 by jokang            #+#    #+#             */
/*   Updated: 2021/12/28 17:11:17 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

enum { BUFFER_SIZE = 5 }; 



int build_queue_malloc(t_queue **queue)
{
	*queue = (t_queue *)malloc(sizeof(t_queue));
	if (*queue == NULL)
	{
		return (FALSE);
	}

	(*queue)->buffer_pa = ((char *)malloc(sizeof(char) * BUFFER_SIZE));
	if ((*queue)->buffer_pa == NULL)
	{
		free(*queue);
		return (FALSE);
	}

	(*queue)->front = 0;
	(*queue)->back = 0;
	(*queue)->num_count = 0;


	return (TRUE);
}

int	is_queue_empty(t_queue *queue_pa)
{
	if (queue_pa->num_count == 0)
	{
		return (TRUE);
	}
	return (FALSE);
}

int	try_enqueue_fd(t_queue *queue_pa, int fd)
{
	if (read(fd, queue_pa->buffer_pa, BUFFER_SIZE) < 0)
	{
		return (FALSE);	
	}
	queue_pa->num_count = BUFFER_SIZE;
	queue_pa->back = BUFFER_SIZE;
	return (TRUE);
}

int	dequeue_by_next_line(t_queue *queue_pa, t_table *head)
{
	char	*buffer;
	char	*string;

	while (head->next != NULL)
	{
		head = head->next;
	}

	buffer = queue_pa->buffer_pa;
	string = head->string_pa + head->capacity;

	while (is_queue_empty(queue_pa) != TRUE && head->capacity != e_TABLE_SIZE)
	{
		*string++ = *buffer++;
		queue_pa->num_count--;
		head->capacity++;

		if (*(string - 1) == '\n')
		{
			return (TRUE);
		}
	}

	return (FALSE);
}

char	*get_next_line(int fd)
{
	static t_queue	*queue_pa;
	t_table			*head;
	char			*result;

	//file -> queue -> head ---> res
	//			|		|
	//			---------		
	//			   loop

	if (queue_pa == NULL && build_queue_malloc(&queue_pa) == FALSE)
		return (NULL);
	//check whether queue is free when try_enqeue_fd is FALSE.
	if (is_queue_empty(queue_pa) == TRUE && try_enqueue_fd(queue_pa, fd) == FALSE)
		return (NULL);

	head = build_table_malloc();
	if (head == NULL)
	{	
		return (NULL);
	}

	while (dequeue_by_next_line(queue_pa, head) == FALSE)
	{
		if (is_queue_empty(queue_pa) == TRUE && is_table_capacity_full(head) == TRUE)
		{
			try_enqueue_fd(queue_pa, fd);
			add_back_table_malloc(&head);
		}
		else if (is_queue_empty(queue_pa) == TRUE)
			try_enqueue_fd(queue_pa, fd);
		else if (is_table_capacity_full(head) == TRUE)
			add_back_table_malloc(&head);
	}

	result = ft_strdup_table_malloc(head);
	ft_lstclear(&head);

	return (result);
}

int	main(void)
{
	int		fd;
	char	*p_pa;

	fd = open("source.txt", O_RDONLY);

	p_pa = get_next_line(fd);
	printf("%s", p_pa);

	p_pa = get_next_line(fd);
	printf("%s", p_pa);
}