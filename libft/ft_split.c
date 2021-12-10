/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:41:46 by jokang            #+#    #+#             */
/*   Updated: 2021/12/10 12:53:57 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_do_split_malloc_or_null(const char *s, char c, char **out_res);
static int	get_w_length(const char *str, char c);
static int	is_charset(char str, char c);
static void	do_free_malloc(char **res, char **tmp_res);

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
	if (result == NULL)
		return (NULL);
	return (ft_do_split_malloc_or_null(s, c, result));
}

static char	**ft_do_split_malloc_or_null(const char *s, char c, char **out_res)
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
				return (NULL);
			}
			ft_strlcpy(*t_result, s, get_w_length(s, c) + 1);
			t_result++;
		}
		s++;
	}
	*t_result = NULL;
	return (out_res);
}

static int	get_w_length(const char *str, char c)
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

static int	is_charset(char str, char c)
{
	if (str == c)
	{
		return (1);
	}
	return (0);
}

static void	do_free_malloc(char **res, char **tmp_res)
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
