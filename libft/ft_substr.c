/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:11:11 by jokang            #+#    #+#             */
/*   Updated: 2021/12/07 17:51:09 by jokang           ###   ########.fr       */
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

	s_length = ft_strlen(s);
	if (start > s_length)
		return (ft_strdup(""));
	if (len > s_length - start + 1)
		pa_str = (char *)malloc(sizeof(char) * s_length - start + 1);
	else
		pa_str = (char *)malloc(sizeof(char) * len + 1);
	if (pa_str == NULL)
		return (NULL);
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
