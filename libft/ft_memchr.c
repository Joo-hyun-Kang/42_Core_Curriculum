/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:12:24 by jokang            #+#    #+#             */
/*   Updated: 2021/11/25 18:57:53 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	char	ch;
	size_t	i;

	p = (char *)s;
	ch = (char)c;
	i = 0;
	while (i < n)
	{
		if (*p == ch)
		{
			return (p);
		}
		p++;
		i++;
	}
	return (NULL);
}
