/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:50:48 by jokang            #+#    #+#             */
/*   Updated: 2022/05/20 16:55:14 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p++ != '\0')
	{
	}
	return (p - s - 1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && *src != '\0')
	{
		*dst++ = *src++;
		i++;
	}	
	if (dstsize != 0)
		*dst = '\0';
	while (*src != '\0')
	{
		src++;
		i++;
	}
	return (i);
}

void	ft_free_spilt_str(char **pp)
{
	while (*pp != NULL)
	{
		free(*pp);
		pp++;
	}
}

void	exit_malloc_fail(void *p)
{
	if (p == NULL)
	{
		exit(1);
	}
}
