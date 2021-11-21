#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int nb);

int main(void)
{
	ft_putnbr(-1);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(1);
	printf("\n");
	ft_putnbr(-2147483647);
}

void ft_putnbr(int nb)
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
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	
	digit = nb + '0';

	write(1, &digit, 1);
}
