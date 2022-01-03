/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:03:40 by jokang            #+#    #+#             */
/*   Updated: 2021/12/15 17:04:00 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_temp;
	char	*src_temp;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
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
		if (tmp->next == NULL)
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
	if (table == NULL)
		return (NULL);
	table->string_pa = (char *)malloc(sizeof(char) * e_TABLE_SIZE);
	if (table->string_pa == NULL)
		return (NULL);
	table->capacity = 0;
	table->next = NULL;
	return (table);
}

int is_table_capacity_full(t_table *table)
{
	while (table->next != NULL)
	{
		table = table->next;
	}
	if (table->capacity == e_TABLE_SIZE)
	{
		return (TRUE);
	}
	return (FALSE);
}

char    *ft_strdup_table_malloc(t_table *head)
{
    char    *p;
	char	*res;
	t_table	*tmp;
	size_t	total;
	size_t	capacitys_count;
	size_t	lst_table_capacity;
	size_t	i;

	tmp = head;
	capacitys_count = 1;
	total = tmp->capacity;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		total += tmp->capacity;
		capacitys_count++;
	}

    p = (char *)malloc(sizeof(char) * total + 1);
	res = p;
	i = 0;
	while (i < capacitys_count - 1)
	{
		ft_memcpy(p, head->string_pa, e_TABLE_SIZE);
		p += e_TABLE_SIZE;
		head = head->next;
		i++;
	}
	lst_table_capacity = total - e_TABLE_SIZE * (capacitys_count - 1);
	ft_memcpy(p, head->string_pa, lst_table_capacity);
	p[total] = '\0';

    return (res);
}

void	ft_lstclear(t_table **lst)
{
	t_table	*p;

	while (*lst != NULL)
	{
		free((*lst)->string_pa);
		p = (*lst)->next;
		free(*lst);
		*lst = p;
	}
}