/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:33:04 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 21:07:24 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_isspace(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		if (result > 9223372036854775807 && sign == 1)
			return (-1);
		if (result > 9223372036854775807 && sign == -1)
			return (-1);
		str++;
	}
	return ((int)(sign * result));
}

int	print_error(enum e_ERROR code)
{
	if (code == SYSTEM_CALL)
		printf("%s\n", "process fail to call system");
	else if (code == ARGUMENT)
		printf("%s\n", "illegal argument");
	return (1);
}

unsigned long	get_current_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NUL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
