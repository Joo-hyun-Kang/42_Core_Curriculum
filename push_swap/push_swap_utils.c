/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:51:50 by jokang            #+#    #+#             */
/*   Updated: 2022/05/19 21:22:14 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_overlap(int *arr, int length)
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (arr[i - 1] == arr[i])
		{
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	is_sorted(int *arr, int length)
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (arr[i - 1] > arr[i])
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	print_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	get_max(t_stack *stack)
{
	int	max;
	int	i;
	int	value;

	max = INT32_MIN;
	i = 0;
	while (i < stack->size)
	{
		value = ft_pop_front(stack);
		if (value > max)
			max = value;
		ft_enqueue(stack, value);
		i++;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int	min;
	int	i;
	int	value;

	min = INT32_MAX;
	i = 0;
	while (i < stack->size)
	{
		value = ft_pop_front(stack);
		if (value < min)
			min = value;
		ft_enqueue(stack, value);
		i++;
	}
	return (min);
}
