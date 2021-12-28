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

#include <stdio.h>

#define BUFFER_SIZE 20

typedef struct s_queue 
{
	//when using queue plase do NULL checking
	char	*buffer;
	size_t	s_front = 0;
	size_t	s_back = 0;
	size_t	s_num_count = 0;
}	queue_t;

typedef struct s_table_list
{
	char	*strings;
	void	*next;
}	table_list_t;

int initialize_queue_malloc(queue_t **queue)
{
	*queue = (queue_t *)malloc(sizeof(queue_t));
	if (*queue == NULL)
			return (false);

	(*queue)->buffer = ((char *)malloc(sizeof(char) * BUFFER_SIZE);
	if ((*queue->buffer) == NULL)
	{
		free(*queue);
		return (false);
	}
	return (true);
}

int	try_enqeue_from_fd()
{
	if (s_num_count == 0)
	{
		if (read(queue->buffer, fd, BUFFER_SIZE) < 0)
			return (FALSE);	
		queue->s_num_count = BUFFER_SIZE;
	}
	return (TRUE)
}

int	try_dequeue_next_line(struct *queue, struct *head)
{
	char	*buffer;
	char	*string;

	buffer = queue->buffer;
	string = head->string;
	
	while (*buffer != '\n')
	{
		*string = *buffer;
		string++;
		buffer++;
	}	
}

char	*get_next_line(int fd)
{
	static queue_t	*queue;
	table_list_t	head;

	if (queue == NULL)
		initalize_queue_malloc(queue);
	if (queue->buffer == NULL)
		return (NULL);
	if (enqeue_from_fd() == FALSE)
		return (NULL);
	
	//make talbe : table->str = (char *)malloc(sizeof(char) * BUFFER_SIZE);

	while (try_dequeue_next_line(queue, head) == TRUE)
	{
		//make table back
		//enqueue_from_fd()
		//
	}
	else 
	
		//strcmp table to res
		//return res;
}
