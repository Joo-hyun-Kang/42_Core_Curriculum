/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:50:59 by jokang            #+#    #+#             */
/*   Updated: 2022/05/20 16:44:55 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_arraylist(t_arraylist *arraylist, int value)
{
	if (!is_arraylist_full(arraylist))
	{
		arraylist->pa_arr[arraylist->length] = value;
		arraylist->length++;
		return (TRUE);
	}
	else
	{
		allocate_arraylist(arraylist);
		return (add_arraylist(arraylist, value));
	}
	return (FALSE);
}

int	is_arraylist_full(t_arraylist *arraylist)
{
	if (arraylist->length >= arraylist->capacity)
	{
		return (TRUE);
	}
	return (FALSE);
}

int	allocate_arraylist(t_arraylist *arraylist)
{
	int	*tmp;

	if (arraylist->pa_arr == NULL || arraylist->capacity == 0)
	{
		arraylist->pa_arr = (int *)malloc(BASIC_CAPACITY * sizeof(int));
		exit_malloc_fail(arraylist->pa_arr);
		arraylist->length = 0;
		arraylist->capacity = BASIC_CAPACITY;
		return (TRUE);
	}
	if (arraylist->pa_arr != NULL && arraylist->capacity != 0)
	{
		tmp = (int *)malloc(arraylist->capacity * 2 * sizeof(int));
		exit_malloc_fail(tmp);
		ft_memcpy(tmp, arraylist->pa_arr, arraylist->length);
		free(arraylist->pa_arr);
		arraylist->pa_arr = tmp;
		tmp = NULL;
		arraylist->capacity *= 2;
		return (TRUE);
	}
	return (FALSE);
}

void	free_arraylist(t_arraylist *arraylist)
{
	free(arraylist->pa_arr);
	arraylist->pa_arr = NULL;
	arraylist->capacity = 0;
	arraylist->length = 0;
}
