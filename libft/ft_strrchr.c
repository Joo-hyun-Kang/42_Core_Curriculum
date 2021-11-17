#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	char	ch;
	char	*p;
	size_t	len;


	ch = (char)c;
	len = ft_strlen(s);
	p = s + len - 1;
	while (p != s)
	{
		if (*p == ch)
		{
			return (p);
		}
		p--;
	}
	return (NULL);
}
