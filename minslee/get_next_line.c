/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:27:23 by minslee           #+#    #+#             */
/*   Updated: 2022/01/18 17:45:38 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static int	get_result_size(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	if (str[index] == '\n')
		index++;
	return (index);
}

static char	*get_result(const char *str, char *result)
{
	size_t	index;

	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
	{
		result[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
		result[index] = str[index];
	result[++index] = 0;
	return (result);
}

static char	*get_buffer(char *str, int fd, char *buffer)
{
	int		buff_size;
	char	*tmp;

	tmp = str;
	buff_size = 1;
	while (find_nl(tmp) < 0 && buff_size != 0)
	{
		buff_size = read(fd, buffer, BUFFER_SIZE);
		if (buff_size == -1)
		{
			free(tmp);
			tmp = NULL;
			return (NULL);
		}
		buffer[buff_size] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*result;
	char			*buffer;
	
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FD_MAX)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	str = get_buffer(str, fd, buffer);
	if (str == NULL || *str == '\0')
	{
		free(str);
		free(buffer);
		str = NULL;
		buffer = NULL;
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (get_result_size(str) + 1));
	result = get_result(str, result);
	str = ft_substr(str, get_result_size(str), ft_strlen(str) - 1);
	free(buffer);
	return (result);
}