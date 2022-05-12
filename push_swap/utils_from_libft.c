#include "push_swap.h"

static char	**ft_do_split_malloc_or_null(const char *s, char c, char **out_res);
static int	get_w_length(const char *str, char c);
static int	is_charset(char str, char c);
static void	do_free_malloc(char **res, char **tmp_res);
char	**ft_split(const char *s, char c);

static int	ft_isspace(char ch);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t n);

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


static int	ft_isspace(char ch)
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
			return (0);
		str++;
	}
	return ((int)(sign * result));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p++ != '\0')
	{
	}
	return (p - s - 1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && *src != '\0')
	{
		*dst++ = *src++;
		i++;
	}	
	if (dstsize != 0)
		*dst = '\0';
	while (*src != '\0')
	{
		src++;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_temp;
	char	*src_temp;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_temp = (char *)dst;
	src_temp = (char *)src;
	i = 0;
	while (i < n)
	{
		*dst_temp++ = *src_temp++;
		i++;
	}
	return (dst);
}
