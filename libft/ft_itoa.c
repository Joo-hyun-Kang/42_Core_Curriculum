/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:17:12 by jokang            #+#    #+#             */
/*   Updated: 2021/12/05 12:51:40 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_nbr(unsigned int n, int is_neg, char *out_res, unsigned int pos)
{
	if (is_neg == 1)
	{
		is_neg = 0;
		*out_res = '-';
		--pos;
		out_res++;
	}
	if (pos > 1)
	{
		put_nbr(n / 10, is_neg, out_res, pos - 1);
	}
	n %= 10;
	*(out_res + --pos) = n + '0';
}

int	get_num_pos(unsigned int n)
{
	unsigned int	n_digit;
	unsigned int	pos;

	n_digit = n / 10;
	pos = 1;
	while (n_digit > 0)
	{
		n_digit /= 10;
		pos++;
	}
	return (pos);
}

char	*ft_itoa(int n)
{
	int				is_negative;
	unsigned int	pos;
	unsigned int	n_abs;
	char			*res;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n_abs = (unsigned int)((n + 1) * -1 + 1);
	}
	else
		n_abs = (unsigned int)n;
	pos = get_num_pos(n_abs);
	if (is_negative == 1)
		pos += 1;
	res = (char *)malloc(sizeof(char) * (pos + 1));
	if (res == NULL)
		return (NULL);
	put_nbr(n_abs, is_negative, res, pos);
	*(res + pos) = '\0';
	return (res);
}
