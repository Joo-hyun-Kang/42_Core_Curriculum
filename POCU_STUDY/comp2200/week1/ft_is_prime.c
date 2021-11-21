#include <stdio.h>

int ft_is_prime(int nb);

int main(void)
{
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(26));
	printf("%d\n", ft_is_prime(29));
}

int ft_is_prime(int nb)
{	
	if (nb == 0 || nb == 1) {
		return 0;
	}

	size_t i;

	for (i = 2; i < (size_t)nb / 2; i++) {
		if (nb % i == 0) {
			return 0;
		}	
	}
	return 1;
}
