#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 0 || c > 255)
	{
		return (0);
	}
	if (c >= 32 && c <= '?' || c >= '@' && c <= '~')
	{
		return (1);
	}
	return (0);
}
