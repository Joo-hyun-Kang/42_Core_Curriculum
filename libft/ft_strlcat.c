/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:18:54 by jokang            #+#    #+#             */
/*   Updated: 2021/12/10 12:45:15 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_shorter_size(char *dst, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dst != '\0' && i < dstsize)
	{
		i++;
		dst++;
	}
	if (*dst == '\0')
		return (0);
	else
		return (1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	copied_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	if (is_shorter_size(dst, dstsize) == 1)
		return (src_length + dstsize);
	copied_length = 0;
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
	return (copied_length);
}
