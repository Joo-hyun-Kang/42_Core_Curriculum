#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && *s1 == *s2)
	{
		i++;
		s1++;
		s2++;
	}
	return (s1 - s2)
}
