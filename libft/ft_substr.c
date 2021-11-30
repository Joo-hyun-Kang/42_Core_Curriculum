/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:11:11 by jokang            #+#    #+#             */
/*   Updated: 2021/11/30 15:13:41 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	char		*end_s;
	char		*pa_str;
	char		*tmp_str;
	size_t		s_length;

	pa_str = (char *)malloc(sizeof(char) * (len + 1));
	if (pa_str == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if (start > s_length)
	{
		*pa_str = '\0';
		return (pa_str);
	}	
	tmp_str = pa_str;
	p = (char *)s + start;
	end_s = (char *)s + s_length;
	while (len > 0 && p < end_s)
	{
		*tmp_str++ = *p++;
		len--;
	}
	*tmp_str = '\0';
	return (pa_str);
}
