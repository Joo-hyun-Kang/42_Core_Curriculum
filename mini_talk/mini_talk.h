/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:20:20 by jokang            #+#    #+#             */
/*   Updated: 2022/05/25 18:23:01 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

# define TRUE (1)
# define FALSE (0)
# define CHAR_BITS (8)

int		ft_isspace(char ch);
int		ft_is_integer(char *str, int *out_res);
int		ft_atoi_helper(char *str, int *out_res, int sign);

void	ft_kill(char **argv, int server_pid);
void	ft_send_null_terminator(int server_pid);

#endif /* MINI_TALK_H */