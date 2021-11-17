#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = 0;
	while (i < n)
	{
		if (*s == ch)
		{
			return (s);
		}
		s++;
		i++;
	}
	return (NULL);
}
