#include <unistd.h>

void ft_putnbr_recursive(int nb)
{
	char digit;

	if (nb == -2147483647) {
		write(1, "-", 1);
		write(1, "2147483647", 10);
		return; 
	}

	if (nb < 0) {
		nb *= -1;
		write(1, "-", 1);	
	}

	if (nb > 9) {
		ft_putnbr_recursive(nb / 10);
		nb %= 10;
	}
	
	digit = nb + '0';

	write(1, &digit, 1);
}
