/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:23:15 by jokang            #+#    #+#             */
/*   Updated: 2022/05/19 21:21:09 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack *a, t_stack *b, t_stack *queue)
{
	int	top_a;

	top_a = ft_pop_front(a);
	ft_push(b, top_a);
	ft_enqueue(queue, (int)COM_PB);
}
