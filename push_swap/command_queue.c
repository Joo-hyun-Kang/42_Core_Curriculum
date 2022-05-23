/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:23:46 by jokang            #+#    #+#             */
/*   Updated: 2022/05/19 21:27:38 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_queue(t_stack *queue)
{
	t_list			*temp;
	int				i;
	int				res1;
	int				res2;
	int				is_even;

	i = 0;
	temp = queue->front;
	while (i < queue->size / 2)
	{
		res1 = temp->value;
		temp = temp->next;
		res2 = temp->value;
		temp = temp->next;
		i++;
		ft_put_queue_helper(res1, res2);
	}
	is_even = queue->size % 2 == 0;
	while (!is_even && temp != NULL)
	{
		ft_put_command(temp->value);
		temp = temp->next;
	}
}

void	ft_put_queue_helper(int r1, int r2)
{
	if (r1 == COM_RA && r2 == COM_RB)
		ft_put_command(COM_RR);
	else if (r1 == COM_RB && r2 == COM_RA)
		ft_put_command(COM_RR);
	else if (r1 == COM_RRA && r2 == COM_RRB)
		ft_put_command(COM_RRR);
	else if (r1 == COM_RRB && r2 == COM_RRA)
		ft_put_command(COM_RRR);
	else if (r1 == COM_RR && r2 == COM_RRR)
		return ;
	else if (r1 == COM_RRR && r2 == COM_RR)
		return ;
	else if (r1 == COM_PA && r2 == COM_PB)
		return ;
	else if (r1 == COM_PB && r2 == COM_PA)
		return ;
	else if ((r1 == COM_RA && r2 == COM_RRA) || (r1 == COM_RB && r2 == COM_RRB))
		return ;
	else if ((r1 == COM_SA && r2 == COM_SA) || (r1 == COM_SB && r2 == COM_SB))
		return ;
	else
	{
		ft_put_command(r1);
		ft_put_command(r2);
	}
}

void	ft_put_command(int command)
{
	if (command == COM_SA)
		write(1, "sa\n", 3);
	else if (command == COM_SB)
		write(1, "sb\n", 3);
	else if (command == COM_SS)
		write(1, "ss\n", 3);
	else if (command == COM_RA)
		write(1, "ra\n", 3);
	else if (command == COM_RB)
		write(1, "rb\n", 3);
	else if (command == COM_RR)
		write(1, "rr\n", 3);
	else if (command == COM_RRA)
		write(1, "rra\n", 4);
	else if (command == COM_RRB)
		write(1, "rrb\n", 4);
	else if (command == COM_RRR)
		write(1, "rrr\n", 4);
	else if (command == COM_PA)
		write(1, "pa\n", 3);
	else if (command == COM_PB)
		write(1, "pb\n", 3);
}
