/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:26:03 by jokang            #+#    #+#             */
/*   Updated: 2021/12/07 17:47:55 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*p;

	res = NULL;
	while (lst != NULL)
	{
		p = ft_lstnew((*f)(lst->content));
		if (p == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&res, p);
	}
	return (res);
}
