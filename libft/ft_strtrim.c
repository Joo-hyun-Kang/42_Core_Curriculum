/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:16:05 by jokang            #+#    #+#             */
/*   Updated: 2021/12/04 13:51:34 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	is_set(char ch, char const *set)
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
	char		*tmp_res;

	p = s1;
	len = 0;
	while (*p != '\0')
	{
		if (!is_set(*p, set))
			len++;	
		p++;
	}
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	tmp_res = res;
	while (*s1 != '\0')
	{
		if (!is_set(*s1, set))
			*tmp_res++ = *s1;
		s1++;
	}
	*tmp_res = '\0';
	return (res);
}
