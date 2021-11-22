/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:14:33 by jokang            #+#    #+#             */
/*   Updated: 2021/11/22 15:14:52 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	
	while (*str == '\t' || *str == '\n' || *str == '\v' 
		   || *str == '\f' || *str == '\r' || *str == ' ')
	{
		str++;
	}
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;	
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (sign * result);
}
