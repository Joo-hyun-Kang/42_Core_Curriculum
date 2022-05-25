/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:03:03 by jokang            #+#    #+#             */
/*   Updated: 2021/11/26 21:12:46 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*s1 == '\0' || *s2 == '\0' || *s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		i++;
		s1++;
		s2++;
	}
	return (0);
}
