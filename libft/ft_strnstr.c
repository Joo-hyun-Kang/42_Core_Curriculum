/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:13:44 by jokang            #+#    #+#             */
/*   Updated: 2021/11/22 15:14:26 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*p_haystack;
	const char	*p_needle;
	size_t	i;

	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	i = 0;
	while (i < len && *haystack != '\0')
	{
		if (*haystack == *needle)
		{
			p_haystack = haystack;
			p_needle = needle;
			while (*p_haystack == *p_needle)
			{
				p_haystack++;
				p_needle++;
			}
			if (*p_needle == '\0')
			{
				return ((char *)haystack);
			}
		}
		i++;
		haystack++;
	}
	return (NULL);
}
