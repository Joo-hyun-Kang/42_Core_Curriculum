int ft_is_prime(int nb)
{	
	if (nb <= 1) {
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
