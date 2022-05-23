/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_chagned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:44:02 by jokang            #+#    #+#             */
/*   Updated: 2022/05/21 22:11:04 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		*dst_temp;
	int		*src_temp;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_temp = (int *)dst;
	src_temp = (int *)src;
	i = 0;
	while (i < n)
	{
		*dst_temp++ = *src_temp++;
		i++;
	}
	return (dst);
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

int	ft_atoi(char *str, int *out_res)
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
