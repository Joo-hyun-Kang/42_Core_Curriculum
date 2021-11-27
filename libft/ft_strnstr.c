/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:13:44 by jokang            #+#    #+#             */
/*   Updated: 2021/11/27 16:36:46 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmpstr(const char *p_hay, const char *p_ne, size_t len)
{
	size_t	j;

	j = 0;
	while (j++ < len && *p_hay != '\0' && *p_hay == *p_ne)
	{
		p_hay++;
		p_ne++;
	}
	if (*p_ne == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && *haystack != '\0')
	{
		if (*haystack == *needle && ft_cmpstr(haystack, needle, len - i))
		{
			return ((char *)haystack);
		}
		i++;
		haystack++;
	}
	return (NULL);
}
