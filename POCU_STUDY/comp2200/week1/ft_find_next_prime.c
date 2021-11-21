#include <stdio.h>

int ft_find_next_prime(int nb);

int main(void)
{
	printf("0: %d\n", ft_find_next_prime(0));
	printf("1: %d\n", ft_find_next_prime(1));
	printf("2: %d\n", ft_find_next_prime(2));
	printf("3: %d\n", ft_find_next_prime(3));
	printf("13: %d\n", ft_find_next_prime(13));
	printf("26: %d\n", ft_find_next_prime(26));
}

int ft_find_next_prime(int nb)
{
	size_t	i;
	int	is_prime;

	is_prime = 0;
	while (is_prime == 0) {
		if (nb < 2) {
			nb++;
			continue;
		}
	
		is_prime = 1;	
		for (i = 2; i <= nb / 2; i++) {
			if (nb % i == 0) {
				is_prime = 0;
				nb++;
				break;
			}
		}
	}

	return nb;
}
