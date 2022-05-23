/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:21:58 by jokang            #+#    #+#             */
/*   Updated: 2022/05/19 21:21:22 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack *a, t_stack *b, t_stack *queue)
{
	ft_ra(a, queue);
	ft_rb(b, queue);
	ft_enqueue(queue, (int)COM_RR);
}

void	ft_rra(t_stack *a, t_stack *queue)
{
	int	bottom;

	bottom = ft_pop_back(a);
	ft_push(a, bottom);
	ft_enqueue(queue, (int)COM_RRA);
}

void	ft_rrb(t_stack *b, t_stack *queue)
{
	int	bottom;

	bottom = ft_pop_back(b);
	ft_push(b, bottom);
	ft_enqueue(queue, (int)COM_RRB);
}

void	ft_rrr(t_stack *a, t_stack *b, t_stack *queue)
{
	ft_rra(a, queue);
	ft_rrb(b, queue);
	ft_enqueue(queue, (int)COM_RRR);
}

void	ft_pa(t_stack *a, t_stack *b, t_stack *queue)
{
	int	top_b;

	top_b = ft_pop_front(b);
	ft_push(a, top_b);
	ft_enqueue(queue, (int)COM_PA);
}
