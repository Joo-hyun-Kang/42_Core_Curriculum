/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:18:54 by jokang            #+#    #+#             */
/*   Updated: 2021/11/27 11:15:26 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	copied_length;
	size_t	dst_length;
	size_t	src_length;

	copied_length = 0;
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	while (*dst != '\0')
	{
		dst++;
		copied_length++;
	}
	while (copied_length + 1 < dstsize && *src != '\0')
	{
		*dst++ = *src++;
		copied_length++;
	}
	*dst = '\0';
	while (*src++ != '\0')
		copied_length++;
	if (dstsize < dst_length)
		return (dst_length + src_length);
	else
		return (copied_length);
}
