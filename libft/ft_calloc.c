/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:16:15 by jokang            #+#    #+#             */
/*   Updated: 2021/11/27 13:53:48 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*temp;
	size_t	len;
	size_t	i;

	len = count * size;
	p = malloc(len);
	if (p == NULL)
		return (NULL);
	temp = (char *)p;
	i = 0;
	while (i < len)
	{
		*temp = 0;
		temp++;
		i++;
	}
	return (p);
}
