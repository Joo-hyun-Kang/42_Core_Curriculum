/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:19:28 by jokang            #+#    #+#             */
/*   Updated: 2021/11/17 16:19:29 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	while (i + 1 < dstsize && *src != '\0')
	{
		*dst++ = *src++;
		i++;		
	}	
	*dst = '\0';
	while (*src != '\0')
	{
		src++;
		i++;
	}
	return (i);
}
