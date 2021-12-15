/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:10:11 by jokang            #+#    #+#             */
/*   Updated: 2021/12/15 20:38:39 by jokang           ###   ########.fr       */
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
	int				read_return;

	if (fd < 3)
		return (NULL);
	
	if (idx_srcs == 0)
	{
		srcs = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_return = read(fd, srcs, BUFFER_SIZE);
		if (read_return < 0)
			return (NULL);
		*(srcs + BUFFER_SIZE) = '\0';
	}

	p = srcs + idx_srcs;
	line_len = ft_get_line_len(p);
	printf("%zu", line_len);
	res = NULL;
	if (line_len != (size_t)-1)
	{
		res = (char	*)malloc(sizeof(char) * line_len);
		ft_memcpy(res, p, line_len);
		idx_srcs += line_len;
	}
	else 
	{
	   free(srcs);
	   srcs = NULL;
	   idx_srcs = 0;
	}

	return (res);
}

size_t		ft_get_line_len(char *srcs)
{
	char	*tmp;

	tmp = srcs;
	while (*tmp != '\0')
	{
		if (*tmp == '\n' || *tmp == EOF)
			return (tmp - srcs + 1);
		tmp++;
	}
	return ((size_t)-1);
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

	close(fd);
}
