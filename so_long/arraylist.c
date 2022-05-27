/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:50:59 by jokang            #+#    #+#             */
/*   Updated: 2022/05/27 20:39:50 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_arraylist(t_arraylist *arraylist, char value)
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
	char	*tmp;

	if (arraylist->pa_arr == NULL || arraylist->capacity == 0)
	{
		arraylist->pa_arr = (char *)malloc(BASIC_CAPACITY * sizeof(char));
		exit_malloc_fail(arraylist->pa_arr);
		arraylist->length = 0;
		arraylist->capacity = BASIC_CAPACITY;
		return (TRUE);
	}
	if (arraylist->pa_arr != NULL && arraylist->capacity != 0)
	{
		tmp = (char *)malloc(arraylist->capacity * 2 * sizeof(char));
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

void	exit_malloc_fail(void *p)
{
	if (p == NULL)
	{
		exit(1);
	}
}
