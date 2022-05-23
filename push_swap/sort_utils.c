/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:54:39 by jokang            #+#    #+#             */
/*   Updated: 2022/05/21 17:37:08 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_a_to_b_exit(t_member *member, t_stack *qu, int cnt)
{
	if (cnt <= 1)
		return ;
	if (cnt == 2)
	{
		swap_size_two_a(member->a, qu);
		return ;
	}
	if (cnt == 3)
	{
		swap_hard_ab(member->a, member->b, qu);
	}
	return ;
}

void	ft_a_rra(t_member *member, t_stack *qu, int cnt)
{
	int	i;

	i = 0;
	while (i++ < cnt)
	{
		ft_rra(member->a, qu);
	}
}

void	ft_b_to_a_exit(t_member *member, t_stack *qu, int cnt)
{
	if (cnt == 1)
	{
		ft_pa(member->a, member->b, qu);
		return ;
	}
	if (cnt == 2)
	{
		swap_size_two_b(member->b, qu);
		ft_pa(member->a, member->b, qu);
		ft_pa(member->a, member->b, qu);
		return ;
	}
	if (cnt == 3)
	{
		swap_hard_ba(member->a, member->b, qu);
	}
}

void	ft_b_rrb(t_member *member, t_stack *qu, int cnt)
{
	int	i;

	i = 0;
	while (i++ < cnt)
	{
		ft_rrb(member->b, qu);
	}
}
