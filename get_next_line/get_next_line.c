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

char	*get_next_line(int fd)
{
	static char		*buffer;
	static size_t	idx_buffer = 0;
	char			*p;
	char			*res;
	size_t			line_len;
	int				is_line;
	char			*tmp;
	size_t			rotation;
	size_t			buffer_length;
	size_t			i;
	
	rotation = 1;
	buffer_length = BUFFER_SIZE * rotation;

	buffer = (char *)malloc(sizeof(char) * (buffer_length * 2) + 1));
	if (read(fd, buffer, buffer_length) < 0)
		return (NULL);
	*(buffer + buffer_length) = '\0';

	is_line = FALSE;

	while(TRUE)
	{
		i = 0;
		while (i < 2)
		{
			p = buffer + idx_buffer;
			is_line = ft_try_get_line_len(p, &line_len);
			printf("lien_len : %zu\n", line_len);
			res = NULL;

			if (is_line == TRUE)
			{
				res = (char	*)malloc(sizeof(char) * line_len + idx);
				ft_memcpy(res, buffer, line_len + idx);
				idx = 0;
				free(srcs);
				break;
			}

			if (i == 0 && read(fd, srcs + (buffer_length / 2), BUFFER_SIZE) < 0)
				return (NULL);

			*(buffer + buffer_length * 2) = '\0';
			i++;	
		}

		if (is_line == TRUE)
			break;
		
		rotation++;
		buffer_length = BUFFER_SIZE * ft_power(2, rotation);
		p = (char *)malloc(sizeof(char) * (buffer_length * 2) + 1);
		ft_memcpy(p, buffer, buffer_length / 2);
		free(buffer);
		buffer = p;
		*(buffer + buffer_length) = '\0';

	}	
	
	return (res);
}

unsigned int	ft_power(unsigned int base, unsigned int n)
{
	if (n == 0)
		return 1;

	return base * ft_power(base, n - 1);
}

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
