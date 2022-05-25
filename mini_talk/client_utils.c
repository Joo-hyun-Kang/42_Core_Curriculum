/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:18:30 by jokang            #+#    #+#             */
/*   Updated: 2022/05/25 18:18:31 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	ft_isspace(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_is_integer(char *str, int *out_res)
{
	int					sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (ft_atoi_helper(str, out_res, sign));
}

int	ft_atoi_helper(char *str, int *out_res, int sign)
{
	unsigned long long	result;
	int					str_len;
	int					i;

	result = 0;
	str_len = ft_strlen(str);
	i = 0;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		if (result > 2147483647 && sign == 1)
			return (FALSE);
		if (result > 2147483648 && sign == -1)
			return (FALSE);
		str++;
		i++;
	}
	if (i != str_len)
		return (FALSE);
	*out_res = (int)(sign * result);
	return (TRUE);
}
