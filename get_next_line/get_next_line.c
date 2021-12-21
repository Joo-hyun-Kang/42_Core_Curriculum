/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:10:11 by jokang            #+#    #+#             */
/*   Updated: 2021/12/21 17:44:49 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	static size_t	idx = 0;
	char			*p;
	char			*res;
	size_t			line_len;
	int				is_line;
	char			*tmp;
	size_t			rotation;
	size_t			buffer_length;
	size_t			i;
	//줄바꿈이 나올 때까지 read한다
		//static은 배열의 2배로 잡는다
	//줄바꿈이 나오면 return 한다
	//EOF가 나오면 return 한다
	//줄바꿈이 나오지 않으면 다시 나머지 버퍼를 채운다
	//없으면 반복한다
	
	rotation = 1;
	is_line = FALSE;
	buffer_length = BUFFER_SIZE * rotation;
	buffer = (char *)malloc(sizeof(char) * (buffer_length * 2) + 1));
	if (read(fd, buffer, buffer_length) < 0)
		return (NULL);
	*(buffer + buffer_length) = '\0';

	while(TRUE)
	{
		i = 0;
		while (i < 2)
		{
			line_len = 0;
			p = srcs + idx_srcs;
			is_line = ft_try_get_line_len(p, &line_len);
			printf("lien_len : %zu\n", line_len);
			res = NULL;

			if (is_line == TRUE)
			{
				res = (char	*)malloc(sizeof(char) * line_len + idx_srcs);
				ft_memcpy(res, srcs, line_len + idx_srcs);
				idx_srcs = 0;
				free(srcs);
				break;
			}

			if (j == 0 && read(fd, srcs + (buffer_length / 2), BUFFER_SIZE) < 0)
				return (NULL);

			*(buffer + buffer_length) = '\0';
			i++;	
		}

		if (is_line == TRUE)
			break;
		
		rotation *= 2;
		buffer_length = BUFFER_SIZE * rotation;
		p = (char *)malloc(sizeof(char) * (buffer_length * 2) + 1);
		ft_memcpy(p, src, buffer_length / 2);
		free(src);
		src = p;

	}	
	
	return (res);
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
