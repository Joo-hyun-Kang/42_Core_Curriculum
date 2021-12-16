/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:17:15 by jokang            #+#    #+#             */
/*   Updated: 2021/12/16 15:43:57 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;

	len = ft_strlen(s1) + 1;
	p = (char *)malloc(sizeof(char) * len);
	if (p == 0)
	{
		return (0);
	}
	ft_strlcpy(p, s1, len);
	return (p);
}
