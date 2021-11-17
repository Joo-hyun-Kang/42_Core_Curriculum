#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char ch;

	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}
