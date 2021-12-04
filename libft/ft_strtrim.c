/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:16:05 by jokang            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/12/04 15:10:33 by jokang           ###   ########.fr       */
=======
/*   Updated: 2021/12/04 13:51:34 by jokang           ###   ########.fr       */
>>>>>>> 8792f57fcb8a279871685530f70fc1013eeb9a9b
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

<<<<<<< HEAD
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
=======
	p = s1;
	len = 0;
	while (*p != '\0')
	{
		if (!is_set(*p, set))
			len++;	
		p++;
>>>>>>> 8792f57fcb8a279871685530f70fc1013eeb9a9b
	}
	len = p - s1 + 1;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
<<<<<<< HEAD
	ft_strlcpy(res, s1, len + 1);
=======
	tmp_res = res;
	while (*s1 != '\0')
	{
		if (!is_set(*s1, set))
			*tmp_res++ = *s1;
		s1++;
	}
	*tmp_res = '\0';
>>>>>>> 8792f57fcb8a279871685530f70fc1013eeb9a9b
	return (res);
}
