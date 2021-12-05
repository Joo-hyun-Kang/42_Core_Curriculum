/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:58:49 by jokang            #+#    #+#             */
/*   Updated: 2021/12/05 16:20:13 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_recursive(unsigned int n, int is_neg, int fd)
{
	char	ch;

	if (is_neg == 1)
	{
		is_neg = 0;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		putnbr_recursive(n / 10, is_neg, fd);
	}
	n %= 10;
	ch = n + '0';
	write(fd, &ch, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				is_negative;
	unsigned int	n_abs;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n_abs = (unsigned int)((n + 1) * -1 + 1);
	}
	else
	{
		n_abs = (unsigned int)n;
	}
	putnbr_recursive(n_abs, is_negative, fd);
}
