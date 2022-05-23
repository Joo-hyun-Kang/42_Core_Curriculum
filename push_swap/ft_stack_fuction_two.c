/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fuction_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:40:16 by jokang            #+#    #+#             */
/*   Updated: 2022/05/20 16:46:09 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_remove(t_stack *rootOrNull)
{
	t_list	*result;

	if (rootOrNull->size == 0)
	{
		return (rootOrNull->front);
	}
	result = rootOrNull->front->next;
	rootOrNull->front->next = NULL;
	free(rootOrNull->front);
	rootOrNull->front = NULL;
	return (result);
}

t_list	*ft_lstnew_malloc(int content)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	exit_malloc_fail(head);
	head->value = content;
	head->next = NULL;
	return (head);
}

void	ft_free(t_stack *stack)
{
	t_list	*temp;

	while (stack->front != NULL)
	{
		temp = stack->front->next;
		free(stack->front);
		stack->front = temp;
		stack->size--;
	}
	stack->front = NULL;
	stack->back = NULL;
}

void	ft_free_t_stack(t_stack **stack)
{
	t_list	*temp;

	while ((*stack)->front != NULL)
	{
		temp = (*stack)->front->next;
		free((*stack)->front);
		(*stack)->front = temp;
		(*stack)->size--;
	}
	(*stack)->front = NULL;
	(*stack)->back = NULL;
	free(*stack);
}

void	ft_set_stack(t_arraylist *arraylist, t_stack **stack, int is_a)
{
	int	i;
	int	*p;

	*stack = (t_stack *)malloc(sizeof(t_stack));
	exit_malloc_fail(*stack);
	(*stack)->front = NULL;
	(*stack)->back = NULL;
	(*stack)->size = 0;
	p = arraylist->pa_arr + arraylist->length - 1;
	i = 0;
	if (is_a)
	{
		while (i < arraylist->length)
		{
			ft_push(*stack, *p);
			p--;
			i++;
		}
	}
}
