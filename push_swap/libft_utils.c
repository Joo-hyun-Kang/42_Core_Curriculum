/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:51:11 by jokang            #+#    #+#             */
/*   Updated: 2022/05/20 16:52:30 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(const char *s, char c)
{
	char		**result;
	const char	*tmp_s;
	int			is_word;
	int			count;

	is_word = 0;
	count = 0;
	tmp_s = s;
	while (*tmp_s != '\0')
	{
		if (is_charset(*tmp_s, c) && is_word == 1)
		{
			is_word = 0;
		}
		else if (!is_charset(*tmp_s, c) && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		tmp_s++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	exit_malloc_fail(result);
	return (ft_do_split_malloc_or_null(s, c, result));
}

char	**ft_do_split_malloc_or_null(const char *s, char c, char **out_res)
{
	char	**t_result;
	int		is_word;

	t_result = out_res;
	is_word = 0;
	while (*s != '\0')
	{
		if (is_charset(*s, c) && is_word == 1)
			is_word = 0;
		else if (!is_charset(*s, c) && is_word == 0)
		{
			is_word = 1;
			*t_result = (char *)malloc(1 * (get_w_length(s, c) + 1));
			if (*t_result == NULL)
			{
				do_free_malloc(out_res, t_result);
				exit(1);
			}
			ft_strlcpy(*t_result, s, get_w_length(s, c) + 1);
			t_result++;
		}
		s++;
	}
	*t_result = NULL;
	return (out_res);
}

int	get_w_length(const char *str, char c)
{
	const char	*p;
	int			length;

	p = str;
	length = 0;
	while (*p != '\0' && is_charset(*p, c) == 0)
	{
		length++;
		p++;
	}
	return (length);
}

int	is_charset(char str, char c)
{
	if (str == c)
	{
		return (1);
	}
	return (0);
}

void	do_free_malloc(char **res, char **tmp_res)
{
	char	**p;
	size_t	count;
	size_t	i;

	count = tmp_res - res;
	i = 0;
	p = res;
	while (i < count)
	{
		free(*p);
		i++;
		p++;
	}
	free(res);
}
