/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fuction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:42:21 by jokang            #+#    #+#             */
/*   Updated: 2022/05/19 21:28:15 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack, int content)
{
	t_list	*new_lst;

	if (stack->size == 0)
	{
		stack->front = ft_lstnew_malloc(content);
		stack->back = stack->front;
	}
	else
	{
		new_lst = ft_lstnew_malloc(content);
		new_lst->next = stack->front;
		stack->front = new_lst;
	}
	stack->size++;
}

void	ft_enqueue(t_stack *stack, int content)
{
	if (stack->size == 0)
	{
		stack->front = ft_lstnew_malloc(content);
		stack->back = stack->front;
	}
	else
	{
		stack->back->next = ft_lstnew_malloc(content);
		stack->back = stack->back->next;
	}
	stack->size++;
}

int	ft_pop_front(t_stack *stack)
{
	int	result;

	result = stack->front->value;
	stack->front = ft_remove(stack);
	stack->size--;
	if (stack->size == 0)
	{
		stack->back = NULL;
	}
	return (result);
}

int	ft_pop_back(t_stack *stack)
{
	int				result;
	int				i;
	t_list			*prev_back;

	if (stack->size == 1)
	{
		return (ft_pop_front(stack));
	}
	i = 1;
	prev_back = stack->front;
	while (i < stack->size - 1)
	{
		prev_back = prev_back->next;
		i++;
	}
	result = stack->back->value;
	free(stack->back);
	stack->back = prev_back;
	stack->back->next = NULL;
	stack->size--;
	return (result);
}

int	ft_peak(t_stack *stack)
{
	int	result;

	result = stack->front->value;
	return (result);
}
