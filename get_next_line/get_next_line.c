/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:10:11 by jokang            #+#    #+#             */
/*   Updated: 2021/12/16 17:21:31 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*srcs;
	static size_t	idx_srcs = 0;
	char			*p;
	char			*res;
	size_t			line_len;
	int				is_line;
	int				read_return;
	char			*tmp;
	
	if (idx_srcs == 0)
	{
		srcs = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_return = read(fd, srcs, BUFFER_SIZE);
		if (read_return < 0)
			return (NULL);
		*(srcs + BUFFER_SIZE) = '\0';
	}

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
	}
	else 
	{
		tmp = (char *)malloc(sizeof(char) * (line_len + idx_srcs + BUFFER_SIZE));
		assert(tmp != NULL);
		if (tmp != NULL)
		{
			ft_memcpy(tmp, srcs, line_len + idx_srcs - 1);
			free(srcs);
			srcs = tmp;
			tmp += line_len - 1;
			//다시 읽어오는 것 코드 중복 제거 하기
			read_return = read(fd, tmp, BUFFER_SIZE);
			if (read_return < 0)
				return (NULL);
			*(srcs + line_len + BUFFER_SIZE - 1) = '\0';
			printf("new srcs : %s\n", srcs);
		}
		idx_srcs += BUFFER_SIZE;
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

int	main(void)
{
	int fd;

	fd = open("source", O_RDONLY);
	assert(fd > -1);

	char	*line;

	line = get_next_line(fd);
	printf("output : %s\n", line);
	
	line = get_next_line(fd);
	printf("output : %s\n", line);
	
	line = get_next_line(fd);
	printf("output : %s\n", line);

	line = get_next_line(fd);
	printf("output : %s\n", line);
	
	line = get_next_line(fd);
	printf("output : %s\n", line);

	line = get_next_line(fd);
	printf("output : %s\n", line);

	close(fd);
}
