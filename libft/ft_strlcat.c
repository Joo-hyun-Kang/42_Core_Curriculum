/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:18:54 by jokang            #+#    #+#             */
/*   Updated: 2021/11/25 19:13:50 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;

	dst_length = 0;
	src_length = ft_strlen(src);
	while (*dst != '\0')
	{
		dst++;
		dst_length++;
	}
	while (dst_length + 1 < dstsize && *src != '\0')
	{
		*dst++ = *src++;
		dst_length++;
	}
	*dst = '\0';
	while (*src != '\0')
	{
		src++;
		dst_length++;
	}
	if (dst_length > dstsize)
		return (src_length);
	else
		return (dst_length);
}
