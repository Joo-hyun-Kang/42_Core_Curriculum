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

int ft_read_str_fd(char* out_buffer, int fd, size_t len)
{
	if (read(fd, out_buffer, len) < 0)
	    return (0);
	*(out_buffer + len) = '\0';
    return (1);
}

char    *ft_strdup_range_malloc(char *src, size_t start, size_t end)
{
    char    *p;
    size_t  range;

    range = end - start;
    p = (char *)malloc(sizeof(char) * range + 1);
    ft_memcpy(p, src, range);
    return (p);
}