#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include "libft.h"

#include <stdio.h>

#define true 1
#define false 0

void    ft_put_pointer(void *pointer, int *out_count);
void    ft_putInt_hex(int num, int isUpper, int *out_count);
void    ft_putnbr_unsigned(unsigned int n, int* out_count);
void	ft_putnbr(int n, int* out_count);
void	ft_putstr(char *s, int *out_count);
void	putnbr_recursive(unsigned int n, int is_neg, int* out_count);


int ft_printf(const char *format, ...)
{
    va_list ap;
    int count = 0;
    va_start(ap, format);
    {
        while (*format != '\0')
        {
            if (*format == '%')
            {
                if (*(format + 1) == 'c')
                {
                    char data = va_arg(ap, int);

                    write(1, &data, 1);

                    format++;
                    format++;
                    count++;
                    continue;
                } 
                else if (*(format + 1) == 's')
                {
                    char *string = va_arg(ap, char*);

                    if (string == NULL)
                    {
                        ft_putstr("(null)", &count);
                    } else {
                        ft_putstr(string, &count);
                    }

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'p')
                {
                    void *p = va_arg(ap, void*);

                    ft_put_pointer(p, &count);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'x')
                {
                    int num = va_arg(ap, int);

                    ft_putInt_hex(num, false, &count);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'X')
                {
                    int num = va_arg(ap, int);

                    ft_putInt_hex(num, true, &count);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'd' || *(format + 1) == 'i')
                {
                    int num = va_arg(ap, int);

                    ft_putnbr(num, &count);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'u')
                {
                    unsigned int num = va_arg(ap, unsigned int);

                    ft_putnbr_unsigned(num, &count);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == '%')
                {
                    write(1, format, 1);

                    format++;
                    format++;
                    count++;
                    continue;
                }
            }
            write(1, format, 1);
            format++;
            count++;
        }
    }
    va_end(ap);

    return count;   
}

void	ft_putstr(char *s, int *out_count)
{
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

void ft_put_pointer(void *pointer, int *out_count) 
{
    if (pointer == NULL) {
        ft_putstr("(nil)", out_count);
        return;
    }

    write(1, "0x", 2);
    *out_count += 2;

    long num = (long)pointer;
    const int LONG_BYTES_COUNT = 8;
    unsigned char *p = (unsigned char *)&num + LONG_BYTES_COUNT - 1;
    char arr[LONG_BYTES_COUNT * 2 + 1];
    int i = 0;
    while (i < LONG_BYTES_COUNT * 2)
    {
        unsigned char byte = *p;

        int tens = byte / 16;
        int unit = byte % 16;

        char ch = tens + '0';
        if (tens > 9) {
                ch = (tens - 10) + 'a';
        }

        arr[i++] = ch;

        ch = unit + '0';
        if (unit > 9) {
                ch = (unit - 10) + 'a';
        }

        arr[i++] = ch;
        p--;
    }
    arr[i] = '\0';
    
    i = 0;
    while (arr[i] == '0') {
        i++;
    }

    while (arr[i] != '\0') {
        write(1, &arr[i], 1);
        (*out_count)++;
        i++;
    }
}

void ft_putInt_hex(int num, int isUpper, int *out_count)
{
    if (num == 0)
    {
        ft_putnbr(num, out_count);
        return ;
    }
    const int INTEGER_BYTES_COUNT = 4;
    char *p = (char *)&num + INTEGER_BYTES_COUNT - 1;
    int i = 0;
    char arr[INTEGER_BYTES_COUNT * 2 + 1];
    //FF FF FF FF
    while (i < INTEGER_BYTES_COUNT * 2)
    {
        unsigned char byte = *p;

        int tens = byte / 16;
        int unit = byte % 16;

        char ch = tens + '0';
        if (tens > 9) {
            if (isUpper)
                ch = (tens - 10) + 'A';
            else
                ch = (tens - 10) + 'a';
        }

        arr[i++] = ch;

        ch = unit + '0';
        if (unit > 9) {
            if (isUpper)
                ch = (unit - 10) + 'A';
            else
                ch = (unit - 10) + 'a';
        }

        arr[i++] = ch;
        p--;
    }
    arr[i] = '\0';
    
    i = 0;
    while (arr[i] == '0') {
        i++;
    }

    while (arr[i] != '\0') {
        write(1, &arr[i], 1);
        (*out_count)++;
        i++;
    }
}

/*
int main(void)
{
    {
        //A00 : 기본 문자 + \n 검사
        ft_printf("12345678\n");
        printf("12345678\n");
    }

    {
        //B00 : %출력 검사
        ft_printf("%%\n");
        printf("%%\n");
    }

    {
        //C00 : 단일 %c 출력 검사 
        ft_printf("%c\n", 'H');
        printf("%c\n", 'H');

        //C01 : 복합 %c 출력 검사
        ft_printf("%c%c%c\n", 'H', 'H', 'H');
        printf("%c%c%c\n", 'H', 'H', 'H');

        //C02 : 복합 %c와 %%와 기본 문자열 섞어서 검사
        printf("12%% %c5678%c\n", 'a', 'b');
        ft_printf("12%% %c5678%c\n", 'a', 'b');
    }

    {
        //D00 : 단일 %c 출력 검사 
        ft_printf("%s\n", "hello world");
        printf("%s\n", "hello world");

        //D01 : 복합 %c 출력 검사
        ft_printf("%s%s%s\n", "hello", "world", "be happy!");
        printf("%s%s%s\n", "hello", "world", "be happy!");

        //D02 : 복합 %s와 %c와 %%와 기본 문자열 섞어서 검사
        printf("12%% %c5678%c %s\n", 'a', 'b', "adding string!");
        ft_printf("12%% %c5678%c %s\n", 'a', 'b', "adding string!");
    }

    {
        //E00 : 단일 %p null 출력 검사
        printf("%p\n", NULL);
        ft_printf("%p\n", NULL);
        
        //E01 : 단일 %p 기본 출력 검사 
        int num = 10;
        int* p = &num;
        printf("%p\n", p);
        ft_printf("%p\n", p);
    }

    // F, G %x, %X 테스트 생략
    {
        //F00 : 단일 %x, %X 0 출력 검사
        printf("%x\n", 0);
        ft_printf("%x\n", 0);

        //F01 : 단일 %x, %X "" 출력 검사
        printf("%x\n", "");
        ft_printf("%x\n", "");
    }

    {
        //H00 : 단일 %d, %i 0 출력 검사
        printf("%d\n", 0);
        ft_printf("%d\n", 0);
        
        //H01 : 단일 %d, %i 양수 출력 검사
        printf("%d\n", 156);
        ft_printf("%d\n", 156);

        //H02 : 단일 %d, %i 음수 출력 검사
        printf("%d\n", -156);
        ft_printf("%d\n", -156);

        //H03 : 단일 %d, %i 최대값 출력 검사
        printf("%d\n", 2147483647);
        ft_printf("%d\n", 2147483647);

        //H04 : 단일 %d, %i 최소값 출력 검사
        printf("%d\n", -2147483647);
        ft_printf("%d\n", -2147483647);

        //H05 : 단일 %d, %i 오버플로우 출력 검사
        printf("%d\n", (int)2147483648);
        ft_printf("%d\n", (int)2147483648);
    }

    {
        ft_printf("%u\n", -156);
        //H00 : 단일 %d, %i 0 출력 검사
        printf("%u\n", 0);
        ft_printf("%u\n", 0);
        
        //H01 : 단일 %d, %i 양수 출력 검사
        printf("%u\n", 156);
        ft_printf("%u\n", 156);

        //H02 : 단일 %d, %i 음수 출력 검사
        printf("%u\n", -156);
        ft_printf("%u\n", -156);
        
        //H03 : 단일 %d, %i 최대값 출력 검사
        printf("%u\n", -1);
        ft_printf("%u\n", -1);

        //H04 : 단일 %d, %i 최소값 출력 검사
        printf("%u\n", -2147483647);
        ft_printf("%u\n", -2147483647);

        //H05 : 단일 %d, %i 오버플로우 출력 검사
        printf("%u\n", (int)2147483648);
        ft_printf("%u\n", (int)2147483648);
    }

}

*/