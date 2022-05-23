/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:07:04 by jokang            #+#    #+#             */
/*   Updated: 2022/05/21 22:15:33 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_size_two_a(t_stack *stack, t_stack *queue)
{
	int	top;
	int	sec_top;

	top = ft_pop_front(stack);
	sec_top = ft_pop_front(stack);
	if (top > sec_top)
	{
		ft_push(stack, sec_top);
		ft_push(stack, top);
		ft_sa(stack, queue);
	}
	else
	{
		ft_push(stack, sec_top);
		ft_push(stack, top);
	}
}

void	swap_size_three_a(t_stack *a, t_stack *queue)
{
	int	arr[3];
	int	sort_order;

	sort_order = INT32_MAX;
	arr[0] = ft_pop_front(a);
	arr[1] = ft_pop_front(a);
	arr[2] = ft_pop_front(a);
	ft_enqueue(a, arr[0]);
	ft_enqueue(a, arr[1]);
	ft_enqueue(a, arr[2]);
	if (arr[0] > arr[1] && arr[0] < arr[2])
		sort_order = THREE_NUM_ORDER_CASE1;
	else if (arr[0] > arr[1] && arr[1] > arr[2])
		sort_order = THREE_NUM_ORDER_CASE2;
	else if (arr[0] > arr[2] && arr[2] > arr[1])
		sort_order = THREE_NUM_ORDER_CASE3;
	else if (arr[0] < arr[2] && arr[2] < arr[1])
		sort_order = THREE_NUM_ORDER_CASE4;
	else if (arr[0] > arr[2] && arr[0] < arr[1])
		sort_order = THREE_NUM_ORDER_CASE5;
	swap_three_num_a(a, sort_order, queue);
}

void	swap_three_num_a(t_stack *stack, int sort_order, t_stack *queue)
{
	if (sort_order == THREE_NUM_ORDER_CASE1)
	{
		ft_sa(stack, queue);
	}
	else if (sort_order == THREE_NUM_ORDER_CASE2)
	{
		ft_sa(stack, queue);
		ft_rra(stack, queue);
	}
	else if (sort_order == THREE_NUM_ORDER_CASE3)
	{
		ft_ra(stack, queue);
	}
	else if (sort_order == THREE_NUM_ORDER_CASE4)
	{
		ft_sa(stack, queue);
		ft_ra(stack, queue);
	}
	else if (sort_order == THREE_NUM_ORDER_CASE5)
	{
		ft_rra(stack, queue);
	}
}

void	swap_size_two_b(t_stack *stack, t_stack *queue)
{
	int	top;
	int	sec_top;

	top = ft_pop_front(stack);
	sec_top = ft_pop_front(stack);
	if (top > sec_top)
	{
		ft_push(stack, sec_top);
		ft_push(stack, top);
	}
	else
	{
		ft_push(stack, sec_top);
		ft_push(stack, top);
		ft_sb(stack, queue);
	}
}

void	swap_five(t_stack *a, t_stack *b, t_stack *queue, int count)
{
	int	max;
	int	min;
	int	top;
	int	i;

	max = get_max(a);
	min = get_min(a);
	i = 0;
	while (i < count)
	{
		top = ft_peak(a);
		if (top == max || top == min)
			ft_pb(a, b, queue);
		else
			ft_ra(a, queue);
		i++;
	}
	swap_size_three_a(a, queue);
	swap_size_two_b(b, queue);
	ft_pa(a, b, queue);
	ft_ra(a, queue);
	ft_pa(a, b, queue);
}
