#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define true (1)
# define false (0)

int     ft_printf(const char *format, ...);
void    ft_print_format(const char *format, int* count, va_list ap);
void    ft_put_pointer(void *pointer, int *out_count);
void    ft_putInt_hex(int num, int *out_count, int isUpper);
void    ft_get_byte_hex(unsigned char *p, char *arr, int isUpper);

void	ft_putchar(char c, int *out_count);
void    ft_putnbr_unsigned(unsigned int n, int* out_count);
void	ft_putnbr(int n, int* out_count);
void	ft_putstr(char *s, int *out_count);
void	putnbr_recursive(unsigned int n, int is_neg, int* out_count);


#endif /* FT_PRINTF_H */