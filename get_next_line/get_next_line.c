/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:10:11 by jokang            #+#    #+#             */
/*   Updated: 2022/01/03 16:05:30 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	(*queue)->is_EOF = FALSE;
	(*queue)->num_count = 0;
	(*queue)->last_count = 0;

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
	int ret;
	
	ret = read(fd, queue_pa->buffer_pa, BUFFER_SIZE);

	if (ret < 0)
		return (FALSE);

	/* EOF is on first of Buffer */
	if (ret == 0)
	{
		queue_pa->is_EOF = TRUE;
		queue_pa->num_count = 0;
		return (FALSE);
	}
	
	/* EOF is on middle of Buffer */
	if (ret < BUFFER_SIZE)
	{
		queue_pa->num_count = ret;
		queue_pa->last_count = ret;
		queue_pa->is_EOF = TRUE;
	}
	else
		queue_pa->num_count = BUFFER_SIZE;
	return (TRUE);
}

int	dequeue_by_next_line(t_queue *queue_pa, t_table *head)
{
	char	*buffer;
	char	*string;

	/* EOF is on first of Buffer */
	if (queue_pa->is_EOF == TRUE && is_queue_empty(queue_pa)== TRUE)
		return (TRUE);

	while (head->next != NULL)
		head = head->next;

	buffer = queue_pa->buffer_pa + (BUFFER_SIZE - queue_pa->num_count);
	string = head->string_pa + head->capacity;

	/* EOF is on middle of Buffer */
	if (queue_pa->is_EOF == TRUE)
		buffer = queue_pa->buffer_pa + (queue_pa->last_count - queue_pa->num_count);

	while (is_queue_empty(queue_pa) != TRUE && head->capacity != e_TABLE_SIZE)
	{
		*string++ = *buffer++;
		queue_pa->num_count--;
		head->capacity++;

		if (*(string - 1) == '\n' || (queue_pa->is_EOF == TRUE && is_queue_empty(queue_pa)== TRUE))
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

char	*get_next_line(int fd)
{
	static t_queue	*queue_pa = NULL;
	t_table			*head;
	char			*result;

	if (queue_pa == NULL && build_queue_malloc(&queue_pa) == FALSE)
		return (NULL);
	if (is_queue_empty(queue_pa) == TRUE && try_enqueue_fd(queue_pa, fd) == FALSE)
	{
		free(queue_pa->buffer_pa);
		free(queue_pa);
		queue_pa = NULL;
		return (NULL);
	}
	head = build_table_malloc();
	if (head == NULL)
		return (NULL);
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
	if (queue_pa->is_EOF && is_queue_empty(queue_pa))
	{
		free(queue_pa->buffer_pa);
		free(queue_pa);
		queue_pa = NULL;
	}
	return (result);
}
