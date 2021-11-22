/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:11:06 by jokang            #+#    #+#             */
/*   Updated: 2021/11/22 16:19:19 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*p;
	size_t	len;


	ch = (char)c;
	len = ft_strlen(s);
	p = (char *)s + len - 1;
	while (p != s)
	{
		if (*p == ch)
		{
			return (p);
		}
		p--;
	}
	return (NULL);
}
