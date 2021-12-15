/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:10:11 by jokang            #+#    #+#             */
/*   Updated: 2021/12/15 18:29:02 by jokang           ###   ########.fr       */
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
		srcs = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	p = srcs + idx_srcs;

	// 예외처리 필요
	read_return = read(fd, p, BUFFER_SIZE);
	assert(read_return > 1);
	
	*(p + BUFFER_SIZE) = '\0';

	res = NULL;
	while (*p != '\0')
	{
		if (*p == '\n')
		{
			line_len = p - srcs + 1;
			printf("%zu\n", line_len);
			res = (char	*)malloc(sizeof(char) * line_len);
			assert(res != 0);
			ft_memcpy(res, srcs, line_len);
			break;
		}
		p++;
	}

	if (*p == '\0')
	{
	   free(srcs);
	   srcs = NULL;
	   idx_srcs = 0;
	}
	else
		idx_srcs = line_len;	

	return (res);
}

int	main(void)
{
	int fd;

	fd = open("source", O_RDONLY);
	assert(fd > -1);

	char	*line;

	line = get_next_line(fd);
	//while (line != NULL)
	//{
		printf("%s\n", line);
		//line = get_next_line(fd);
	//}
	
	close(fd);
}
