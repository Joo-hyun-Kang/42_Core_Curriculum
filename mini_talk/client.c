/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:06:27 by jokang            #+#    #+#             */
/*   Updated: 2022/05/25 22:58:36 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

#define SIGNAL_DELAY (50)

#include <stdio.h>
#include <time.h>

void	ft_kill(char **argv, int server_pid)
{
	unsigned char	*p;
	unsigned char	ch;
	unsigned char	signal;
	int				i;

	clock_t s = clock(); // timer

	p = (unsigned char *)argv[2];
	while (*p != '\0')
	{
		ch = *p++;
		i = 0;
		while (i++ < CHAR_BITS)
		{
			usleep(SIGNAL_DELAY);
			signal = 128;
			signal &= ch;
			ch <<= 1;
			if (signal == 0)
				kill((pid_t)server_pid, SIGUSR1);
			else
				kill((pid_t)server_pid, SIGUSR2);
		}
	}
	if (*p == '\0')
		ft_send_null_terminator(server_pid);

	clock_t f = clock();
	printf("Duration: %lf [sec]\n", (double)(f - s)/CLOCKS_PER_SEC); // timer
}

void	ft_send_null_terminator(int server_pid)
{
	int	i;

	i = 0;
	while (i < CHAR_BITS)
	{
		usleep(SIGNAL_DELAY);
		kill((pid_t)server_pid, SIGUSR1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	value;

	if (argc != 3 || !ft_is_integer(argv[1], &value))
	{
		ft_putstr_fd("Wrong Input!\n", 1);
		return (-1);
	}
	ft_kill(argv, value);
	return (0);
}
