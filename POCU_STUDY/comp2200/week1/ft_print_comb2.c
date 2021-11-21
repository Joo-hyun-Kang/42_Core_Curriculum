#include <unistd.h>

void ft_print_comb2(void)
{
	size_t i;
	size_t j;
	
	for (i = 0; i <= 98; i++) {
		for (j = i + 1; j <= 99; j++) {
			put_number(i);
			write(1, " ", 1);
			put_number(j);
			if (i != 98) {
				write(1, ",", 1);
			}	
		}
	}

}

void put_number(int nb)
{
	int	position;
	int	temp;
	char	digit;

	temp = nb / 10;
	position = 1;

	while (temp > 0) {
		temp /= 10;
		position *= 10;
	}
	
	if (position <= 1) {
		write(1, "0", 1);
	}

	while (position > 0) {
		digit = nb / position + '0';
		write(1, &digit, 1);
		nb %= position;
		position /= 10;	
	}
}
