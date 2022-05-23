/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:13:21 by jokang            #+#    #+#             */
/*   Updated: 2021/12/10 12:49:52 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_set(char ch, char const *set)
{
	while (*set != '\0')
	{
		if (*set == ch)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*p;
	size_t		len;
	char		*res;

	while (*s1 != '\0' && is_set(*s1, set))
	{
		s1++;
	}
	if (*s1 == '\0')
		return (ft_strdup(""));
	p = s1 + ft_strlen(s1);
	while (is_set(*p, set) || *p == '\0')
	{
		p--;
	}
	len = p - s1 + 1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}
