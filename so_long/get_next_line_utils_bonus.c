/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:45:58 by jokang            #+#    #+#             */
/*   Updated: 2022/05/30 16:08:14 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_temp;
	char	*src_temp;
	size_t	i;

	if (dst == FT_NULL && src == FT_NULL)
		return (FT_NULL);
	dst_temp = (char *)dst;
	src_temp = (char *)src;
	i = 0;
	while (i < n)
	{
		*dst_temp++ = *src_temp++;
		i++;
	}
	return (dst);
}

int	add_back_table_malloc(t_table **head)
{
	t_table	*tmp;

	tmp = *head;
	while (TRUE)
	{
		if (tmp->next == FT_NULL)
		{
			tmp->next = build_table_malloc();
			return (TRUE);
		}
		tmp = tmp->next;
	}
}

t_table	*build_table_malloc(void)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	table->string_pa = (char *)malloc(sizeof(char) * e_size);
	table->capacity = 0;
	table->next = FT_NULL;
	return (table);
}

int	is_table_capacity_full(t_table *table)
{
	while (table->next != FT_NULL)
	{
		table = table->next;
	}
	if (table->capacity == e_size)
	{
		return (TRUE);
	}
	return (FALSE);
}

char	*ft_strdup_table_malloc(t_table *head)
{
	char	*res;
	t_table	*tmp;
	size_t	total;
	size_t	count;
	size_t	i;

	tmp = head;
	count = 0;
	total = 0;
	while (tmp != FT_NULL)
	{
		total += tmp->capacity;
		tmp = tmp->next;
		count++;
	}
	res = (char *)malloc(sizeof(char) * total + 1);
	i = 0;
	while (i < count - 1)
	{
		ft_memcpy(&res[i++ *e_size], head->string_pa, e_size);
		head = head->next;
	}
	ft_memcpy(&res[i * e_size], head->string_pa, total - e_size * (count - 1));
	res[total] = '\0';
	return (res);
}
