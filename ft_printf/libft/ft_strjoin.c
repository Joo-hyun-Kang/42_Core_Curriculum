/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:36:22 by jokang            #+#    #+#             */
/*   Updated: 2021/11/30 12:22:22 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str_len;
	char	*p_str;

	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p_str = (char *)malloc(sizeof(char) * str_len);
	if (p_str == NULL)
		return (NULL);
	ft_strlcpy(p_str, s1, str_len);
	ft_strlcat(p_str, s2, str_len);
	return (p_str);
}
