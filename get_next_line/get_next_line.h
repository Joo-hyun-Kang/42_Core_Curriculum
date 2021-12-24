/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:40 by jokang            #+#    #+#             */
/*   Updated: 2021/12/16 17:08:33 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>

# define TRUE (1)
# define FALSE (0)

char	*get_next_line(int fd);
int		ft_try_get_line_len(char *srcs, size_t *line_len);

void	*ft_memcpy(void *dst, const void *src, size_t n);
int     ft_read_str_fd(char* out_buffer, int fd, size_t len);
char    *ft_strdup_range_malloc(char *src, size_t start, size_t end);

#endif /* GET_NEXT_LINE_H */



