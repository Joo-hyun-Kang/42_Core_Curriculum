/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:44:16 by minslee           #+#    #+#             */
/*   Updated: 2022/01/20 22:48:31 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_MAX (10256)
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

enum { BUFFER_SIZE = 42 };

int		ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, int len);
int		find_nl(char *str);

char	*get_next_line(int fd);
#endif
