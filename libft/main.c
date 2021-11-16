#include "libft.h"

int main(void)
{
	printf("ft_isalpha is testing...\n");
	printf("argumnet -1 and output expect 0 : %d\n", ft_isalpha(-1));
	printf("argumnet EOF and output expect 0 : %d\n", ft_isalpha(EOF));
	printf("argumnet 65 and output expect 1 : %d\n", ft_isalpha(65));
	printf("argumnet 64 and output expect 0 : %d\n", ft_isalpha(64));
	printf("argumnet 127 and output expect 0 : %d\n", ft_isalpha(127));

	printf("ft_strlen is testing...\n");
	printf("argument abcd and output expect 4 : %d\n", ft_strlen("abcd"));
}
