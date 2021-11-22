/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:07:42 by jokang            #+#    #+#             */
/*   Updated: 2021/11/22 16:41:11 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{

}

}
	char	arr[len];
	char	*p;
	size_t	i;

	p = (char *)src;
	i = 0;
	while (i < len)
	{
		arr[i++] = *p++;
	}
	p = (char *)dst;
	i = 0;
	while (i < len)
	{
		*p++ = arr[i++]; 
	}
	return (dst);
}
