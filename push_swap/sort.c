/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:10:06 by jokang            #+#    #+#             */
/*   Updated: 2022/05/21 17:54:32 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_member *member, t_stack *pivot, t_stack *pa_out_queue)
{
	if (member->a->size == 2)
	{
		swap_size_two_a(member->a, pa_out_queue);
	}
	else if (member->a->size == 3)
	{
		swap_size_three_a(member->a, pa_out_queue);
	}
	else if (member->a->size == 5)
	{
		swap_five(member->a, member->b, pa_out_queue, member->a->size);
	}
	else
	{
		ft_a_to_b(member, pivot, pa_out_queue, member->a->size);
	}
}

void	ft_a_to_b(t_member *mem, t_stack *pvts, t_stack *qu, int cnt)
{
	int	ra_count;
	int	pb_count;
	int	pivot;

	if (cnt <= 3)
		return (ft_a_to_b_exit(mem, qu, cnt));
	ra_count = 0;
	pb_count = 0;
	pivot = ft_pop_front(pvts);
	while (cnt--)
	{
		if (ft_peak(mem->a) > pivot)
		{
			ft_ra(mem->a, qu);
			ra_count++;
		}
		else
		{
			ft_pb(mem->a, mem->b, qu);
			pb_count++;
		}
	}
	ft_a_rra(mem, qu, ra_count);
	ft_a_to_b(mem, pvts, qu, ra_count);
	ft_b_to_a(mem, pvts, qu, pb_count);
}

void	ft_b_to_a(t_member *mem, t_stack *pvts, t_stack *qu, int cnt)
{
	int	rb_count;
	int	pa_count;
	int	pivot;

	if (cnt <= 3)
		return (ft_b_to_a_exit(mem, qu, cnt));
	rb_count = 0;
	pa_count = 0;
	pivot = ft_pop_front(pvts);
	while (cnt--)
	{
		if (ft_peak(mem->b) > pivot)
		{
			ft_pa(mem->a, mem->b, qu);
			pa_count++;
		}
		else
		{
			ft_rb(mem->b, qu);
			rb_count++;
		}
	}
	ft_b_rrb(mem, qu, rb_count);
	ft_a_to_b(mem, pvts, qu, pa_count);
	ft_b_to_a(mem, pvts, qu, rb_count);
}
