/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:33:43 by jokang            #+#    #+#             */
/*   Updated: 2022/03/24 14:11:25 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LONG_BYTES_COUNT 8
#define INTEGER_BYTES_COUNT 4

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			ft_print_format(format, &count, ap);
			format++;
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(ap);
	return (count);
}

void	ft_print_format(const char *format, int *count, va_list ap)
{
	if (*(format + 1) == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (*(format + 1) == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (*(format + 1) == 'p')
		ft_put_pointer(va_arg(ap, void *), count);
	else if (*(format + 1) == 'x')
		ft_putInt_hex(va_arg(ap, int), count, FALSE);
	else if (*(format + 1) == 'X')
		ft_putInt_hex(va_arg(ap, int), count, TRUE);
	else if (*(format + 1) == 'd' || *(format + 1) == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (*(format + 1) == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int), count);
	else if (*(format + 1) == '%')
		ft_putchar('%', count);
}

void	ft_put_pointer(void *pointer, int *out_count)
{
	long			num;
	unsigned char	*p;
	char			arr[LONG_BYTES_COUNT * 2 + 1];
	int				i;

	if (pointer == NULL)
	{
		ft_putstr("0x0", out_count);
		return ;
	}
	ft_putstr("0x", out_count);
	num = (long)pointer;
	p = (unsigned char *)&num + LONG_BYTES_COUNT - 1;
	i = 0;
	while (i < LONG_BYTES_COUNT * 2)
	{
		ft_get_byte_hex(p--, &arr[i], FALSE);
		i += 2;
	}
	arr[i] = '\0';
	i = 0;
	while (arr[i] == '0')
		i++;
	while (arr[i] != '\0')
		ft_putchar(arr[i++], out_count);
}

void	ft_putInt_hex(int num, int *out_count, int isUpper)
{
	unsigned char	*p;
	int				i;
	char			arr[INTEGER_BYTES_COUNT * 2 + 1];

	if (num == 0)
	{
		ft_putnbr(num, out_count);
		return ;
	}
	p = (unsigned char *)&num + INTEGER_BYTES_COUNT - 1;
	i = 0;
	while (i < INTEGER_BYTES_COUNT * 2)
	{
		ft_get_byte_hex(p, &arr[i], isUpper);
		p--;
		i += 2;
	}
	arr[i] = '\0';
	i = 0;
	while (arr[i] == '0')
		i++;
	while (arr[i] != '\0')
		ft_putchar(arr[i++], out_count);
}

void	ft_get_byte_hex(unsigned char *p, char *arr, int isUpper)
{
	int		tens;
	int		unit;
	char	ch;

	tens = *p / 16;
	unit = *p % 16;
	ch = tens + '0';
	if (tens > 9)
	{
		if (isUpper)
			ch = (tens - 10) + 'A';
		else
			ch = (tens - 10) + 'a';
	}
	*arr++ = ch;
	ch = unit + '0';
	if (unit > 9)
	{
		if (isUpper)
			ch = (unit - 10) + 'A';
		else
			ch = (unit - 10) + 'a';
	}
	*arr++ = ch;
}
