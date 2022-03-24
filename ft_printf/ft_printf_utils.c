#include "ft_printf.h"

void	ft_putchar(const char c, int *out_count)
{
	write(1, &c, 1);
    (*out_count)++;
}

void	ft_putstr(char *s, int *out_count)
{
	if (s == NULL)
    {
        ft_putstr("(null)", out_count);
		return ;
    }
    
    while (*s != '\0')
	{
		write(1, s, 1);
        (*out_count)++;
		s++;
	}
}

void	putnbr_recursive(unsigned int n, int is_neg, int* out_count)
{
	char	ch;

	if (is_neg == 1)
	{
		is_neg = 0;
		write(1, "-", 1);
        (*out_count)++;
	}
	if (n > 9)
	{
		putnbr_recursive(n / 10, is_neg, out_count);
	}
	n %= 10;
	ch = n + '0';
	write(1, &ch, 1);
    (*out_count)++;
}

void	ft_putnbr(int n, int* out_count)
{
	int				is_negative;
	unsigned int	n_abs;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n_abs = (unsigned int)((n + 1) * -1 + 1);
	}
	else
	{
		n_abs = (unsigned int)n;
	}
	putnbr_recursive(n_abs, is_negative, out_count);
}

void ft_putnbr_unsigned(unsigned int n, int* out_count)
{
	char	ch;

	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, out_count);
	}
	n %= 10;
	ch = n + '0';
	write(1, &ch, 1);
    (*out_count)++;
}