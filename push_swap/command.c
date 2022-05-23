/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:20:38 by jokang            #+#    #+#             */
/*   Updated: 2022/05/19 21:21:36 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, t_stack *queue)
{
	int	top;
	int	second_top;

	top = ft_pop_front(a);
	second_top = ft_pop_front(a);
	ft_push(a, top);
	ft_push(a, second_top);
	ft_enqueue(queue, (int)COM_SA);
}

void	ft_sb(t_stack *b, t_stack *queue)
{
	int	top;
	int	second_top;

	top = ft_pop_front(b);
	second_top = ft_pop_front(b);
	ft_push(b, top);
	ft_push(b, second_top);
	ft_enqueue(queue, (int)COM_SB);
}

void	ft_ss(t_stack *a, t_stack *b, t_stack *queue)
{
	ft_sa(a, queue);
	ft_sb(b, queue);
	ft_enqueue(queue, (int)COM_SS);
}

void	ft_ra(t_stack *a, t_stack *queue)
{
	int	top;

	top = ft_pop_front(a);
	ft_enqueue(a, top);
	ft_enqueue(queue, (int)COM_RA);
}

void	ft_rb(t_stack *b, t_stack *queue)
{
	int	top;

	top = ft_pop_front(b);
	ft_enqueue(b, top);
	ft_enqueue(queue, (int)COM_RB);
}
