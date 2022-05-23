/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:55 by jokang            #+#    #+#             */
/*   Updated: 2022/05/21 22:34:56 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_hard_ab(t_stack *a, t_stack *b, t_stack *qu)
{
	int	arr[3];
	int	sort_order;

	sort_order = INT32_MAX;
	arr[0] = ft_pop_front(a);
	arr[1] = ft_pop_front(a);
	arr[2] = ft_pop_front(a);
	ft_push(a, arr[2]);
	ft_push(a, arr[1]);
	ft_push(a, arr[0]);
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
	else if (arr[0] < arr[1] && arr[1] && arr[2])
		sort_order = THREE_NUM_ORDER_CASE6;
	swap_hard_ab_help(a, b, sort_order, qu);
}

void	swap_hard_ab_help(t_stack *a, t_stack *b, int num, t_stack *qu)
{
	if (num == THREE_NUM_ORDER_CASE1)
	{
		ft_sa(a, qu);
	}
	else if (num == THREE_NUM_ORDER_CASE2)
	{
		ft_sa(a, qu);
		ft_pb(a, b, qu);
		ft_sa(a, qu);
		ft_ra(a, qu);
		ft_pa(a, b, qu);
		ft_rra(a, qu);
	}
	else if (num == THREE_NUM_ORDER_CASE3)
	{
		ft_sa(a, qu);
		ft_ra(a, qu);
		ft_sa(a, qu);
		ft_rra(a, qu);
	}
	else
	{
		swap_ab_help(a, b, num, qu);
	}
}

void	swap_ab_help(t_stack *a, t_stack *b, int num, t_stack *qu)
{
	if (num == THREE_NUM_ORDER_CASE4)
	{
		ft_ra(a, qu);
		ft_sa(a, qu);
		ft_rra(a, qu);
	}
	else if (num == THREE_NUM_ORDER_CASE5)
	{
		ft_ra(a, qu);
		ft_sa(a, qu);
		ft_pb(a, b, qu);
		ft_rra(a, qu);
		ft_pa(a, b, qu);
	}
	else if (num == THREE_NUM_ORDER_CASE6)
	{	
	}
}
