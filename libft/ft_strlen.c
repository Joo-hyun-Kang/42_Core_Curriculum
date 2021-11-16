#include "libft.h"

size_t ft_strlen(const char *s)
{
	const char *p;

	p = s;
	while (*p++ != '\0')
	{
	}
	return p - s - 1;
}
