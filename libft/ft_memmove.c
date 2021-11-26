/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:22:27 by jokang            #+#    #+#             */
/*   Updated: 2021/11/26 13:50:44 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp_dst;
	char	*temp_src;

	i = 0;
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	if (temp_dst < temp_src)
	{
		while (i++ < len)
		{
			*temp_dst++ = *temp_src++;
		}
	}
	else
	{
		temp_dst += len - 1;
		temp_src += len - 1;
		while (i++ < len)
		{
			*temp_dst-- = *temp_src--;
		}
	}
	return (dst);
}
