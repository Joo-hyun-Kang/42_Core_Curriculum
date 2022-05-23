/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:05:05 by jokang            #+#    #+#             */
/*   Updated: 2022/05/19 22:11:40 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int start, int end, int *arr)
{
	int	pivot;
	int	pivot_pos;

	if (start >= end)
	{
		return ;
	}
	pivot = end;
	pivot_pos = ft_divdie_and_conquer(start, pivot, arr);
	quick_sort(start, pivot_pos - 1, arr);
	quick_sort(pivot_pos + 1, end, arr);
}

int	ft_divdie_and_conquer(int left, int right, int *nums)
{
	int	swap_pos;
	int	pivot;
	int	i;

	swap_pos = left;
	pivot = nums[right];
	i = left;
	while (i < right)
	{
		if (nums[i] < pivot)
		{
			ft_swap(nums, i, swap_pos);
			swap_pos++;
		}
		i++;
	}
	ft_swap(nums, right, swap_pos);
	return (swap_pos);
}

void	ft_swap(int *nums, int a, int b)
{
	int	temp;

	temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}
