/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:18:47 by jokang            #+#    #+#             */
/*   Updated: 2022/05/25 18:46:06 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	server_handler(int signal_num, siginfo_t *info, void *context)
{
	static int			i = 0;
	static char			ch = 0;

	context = NULL;
	info = NULL;
	if (signal_num == SIGUSR1)
		ch |= 0;
	else if (signal_num == SIGUSR2)
		ch |= 1;
	i++;
	if (i == CHAR_BITS)
	{
		ft_putchar_fd(ch, 1);
		i = 0;
		ch = 0;
	}
	else
		ch <<= 1;
}

int	main(void)
{
	struct sigaction	sigact;

	ft_putstr_fd("Server Pid : ", 1);
	ft_putnbr_fd((int)getpid(), 1);
	ft_putstr_fd("\n", 1);
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = server_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
	{
		pause();
	}
	ft_putstr_fd("exit?\n", 1);
}
