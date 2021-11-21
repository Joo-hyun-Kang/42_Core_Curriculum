int ft_find_next_prime(int nb)
{
	size_t	i;
	int		is_prime;

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
