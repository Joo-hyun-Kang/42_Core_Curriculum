/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:13:37 by jokang            #+#    #+#             */
/*   Updated: 2021/11/17 15:49:14 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*p;
	size_t			i;
	
	ch = (unsigned char)c;
	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*p = ch;
		p++;
		i++;	
	}
	return (b);
}
