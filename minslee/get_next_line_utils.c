/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:44:56 by minslee           #+#    #+#             */
/*   Updated: 2022/01/20 22:44:38 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		index;

	index = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == 0)
		return (0);
	while (index < ft_strlen(s1))
	{
		dest[index] = s1[index];
		index++;
	}
	dest[index] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		index1;
	int		index2;

	index1 = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1)
	{
		while (s1[index1])
		{
			dest[index1] = s1[index1];
			index1++;
		}
	}
	index2 = 0;
	while (s2[index2])
		dest[index1++] = s2[index2++];
	dest[index1] = '\0';
	free(s1);
	s1 = NULL;
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*dest;
	int		index;

	index = 0;
	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
	{
		dest = (char *)malloc(sizeof(char));
		*dest = 0;
		free(s);
		return (dest);
	}
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	while (index < len && s[start + index] != '\0')
	{
		dest[index] = s[start + index];
		index++;
	}
	dest[index] = 0;
	free(s);
	s = NULL;
	return (dest);
}

int	find_nl(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}
