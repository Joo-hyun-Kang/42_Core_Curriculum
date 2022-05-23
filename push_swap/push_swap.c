/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:54:43 by jokang            #+#    #+#             */
/*   Updated: 2022/05/21 23:03:43 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_arraylist			pa_arraylist;
	t_stack				pa_pivot;
	t_stack				pa_out_queue;
	t_member			member;

	if (argc < 2)
		exit(1);
	allocate_arraylist(&pa_arraylist);
	is_parse_argv_malloc(argc, argv, &pa_arraylist);
	get_optiml_pivot(&pa_arraylist, &pa_pivot);
	ft_set_stack(&pa_arraylist, &member.a, TRUE);
	ft_set_stack(&pa_arraylist, &member.b, FALSE);
	free_arraylist(&pa_arraylist);
	ft_sort(&member, &pa_pivot, &pa_out_queue);
	ft_free_t_stack(&member.a);
	ft_free_t_stack(&member.b);
	ft_free(&pa_pivot);
	ft_put_queue(&pa_out_queue);
	ft_free(&pa_out_queue);
}

void	get_optiml_pivot(t_arraylist *arraylist, t_stack *pivot)
{
	int	*arr_copy;
	int	i;
	int	len;

	len = arraylist->length;
	arr_copy = (int *)malloc(sizeof(int) * len);
	exit_malloc_fail(arr_copy);
	i = 0;
	while (i < len)
	{
		arr_copy[i] = arraylist->pa_arr[i];
		i++;
	}
	quick_sort(0, len - 1, arr_copy);
	if (is_overlap(arr_copy, len))
		print_error_exit();
	if (is_sorted(arraylist->pa_arr, len))
		exit(1);
	get_optimal_pivot_recur(arr_copy, pivot, 0, len - 1);
	free(arr_copy);
	arr_copy = NULL;
}

void	get_optimal_pivot_recur(int *arr, t_stack *stack, int s, int e)
{
	int	mid;

	if (e - s <= 2)
		return ;
	mid = (s + e) / 2;
	ft_enqueue(stack, arr[mid]);
	get_optimal_pivot_recur(arr, stack, mid + 1, e);
	get_optimal_pivot_recur(arr, stack, s, mid);
}

void	is_parse_argv_malloc(int argc, char **argv, t_arraylist *pa_arraylist)
{
	int		i;
	int		value;
	char	**pa_splited_str;
	char	**pp;

	i = 0;
	while (++i < argc)
	{
		pa_splited_str = ft_split(argv[i], ' ');
		pp = pa_splited_str;
		while (*pp != NULL)
		{
			value = 0;
			if (ft_atoi(*pp, &value) == FALSE)
				print_error_exit();
			add_arraylist(pa_arraylist, value);
			pp++;
		}
		ft_free_spilt_str(pa_splited_str);
		free(pa_splited_str);
	}
	if (pa_arraylist->length == 0)
		print_error_exit();
	if (pa_arraylist->length == 1)
		exit(1);
}
