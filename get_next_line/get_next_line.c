/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:10:11 by jokang            #+#    #+#             */
/*   Updated: 2021/12/24 14:58:40 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

#define BUFFER_SIZE 20

char	*get_next_line(int fd)
{
	static char		*buffer;
	static size_t	buffer_length;
	static size_t	idx_buffer = 0;
	char			*res;
	char			*p;
	size_t			line_length;
	int				is_line;
	size_t			rotation;
	
	if (idx_buffer == 0)
	{
		rotation = 1;
		buffer_length = BUFFER_SIZE * rotation;
		buffer = (char *)malloc(sizeof(char) * (buffer_length + 1));

		if (ft_read_str_fd(buffer, fd, buffer_length) == 0)
			return (NULL);
	}

	is_line = FALSE;
	res = NULL;

	while(TRUE)
	{
		p = buffer + idx_buffer;
		is_line = ft_try_get_line_len(p, &line_length);
		idx_buffer = line_length;
		printf("lien_len : %zu\n", line_length);

		if (is_line == TRUE)
		{
			res = ft_strdup_range_malloc(buffer, 0, line_length + idx_buffer);

			p = NULL;
			if (idx_buffer == buffer_length)
				idx_buffer = 0;
			else
				p = ft_strdup_range_malloc(buffer, idx_buffer, buffer_length);

			free(buffer);
			buffer = p;

			break;
		}
		
		rotation++;
		buffer_length = BUFFER_SIZE * rotation;
		p = (char *)malloc(sizeof(char) * (buffer_length + 1));
		ft_memcpy(p, buffer, buffer_length / 2);
		free(buffer);
		buffer = p;
		if (ft_read_str_fd(buffer + idx_buffer, fd, buffer_length / 2) < 0)
			return (NULL);
	}	
	
	return (res);
}

/*
unsigned int	ft_power(unsigned int base, unsigned int n)
{
	if (n == 0)
		return 1;

	return base * ft_power(base, n - 1);
}
*/

int	ft_try_get_line_len(char *srcs, size_t *out_len)
{
	char	*tmp;
	int		is_get_line;

	is_get_line = FALSE;
	tmp = srcs;
	while (*tmp != '\0')
	{
		if (*tmp == '\n' || *tmp == EOF)
		{
			is_get_line = TRUE;
			break;
		}	
		tmp++;
	}
	*out_len = tmp - srcs + 1;
	return (is_get_line);
}

int main(void)
{
	int		fd;
	char	*p;

	fd = open("source.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("FILE_OPEN ERROR");
		return 0;
	}
	
	p = get_next_line(fd);

	while (p != NULL)
	{
		printf("%s", p);
		free(p);
		p = get_next_line(fd);
	}


	return 1;
}