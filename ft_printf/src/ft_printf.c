#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include "libft.h"

#include <stdio.h>

#define true 1
#define false 0

void ft_put_pointer(void *pointer);
void ft_putInt_hex(int num, int isUpper);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);

int ft_printf(const char *format, ...)
{
    va_list ap;

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
                    continue;
                } 
                else if (*(format + 1) == 's')
                {
                    char *string = va_arg(ap, char*);

                    ft_putstr_fd(string, 1);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'p')
                {
                    void *p = va_arg(ap, void*);

                    ft_put_pointer(p);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'x')
                {
                    int num = va_arg(ap, int);

                    ft_putInt_hex(num, false);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'X')
                {
                    int num = va_arg(ap, int);

                    ft_putInt_hex(num, true);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'd' || *(format + 1) == 'i')
                {
                    int num = va_arg(ap, int);

                    ft_putnbr_fd(num, 1);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'u')
                {
                    unsigned int num = va_arg(ap, unsigned int);

                    ft_putnbr_unsigned_fd(num, 1);

                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == '%')
                {
                    write(1, format, 1);

                    format++;
                    format++;
                    continue;
                }
            }
            write(1, format, 1);
            format++;
        }
    }
    va_end(ap);

    return 0;   
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	ch;

	if (n > 9)
	{
		ft_putnbr_unsigned_fd(n / 10, fd);
	}
	n %= 10;
	ch = n + '0';
	write(fd, &ch, 1);
}

void ft_put_pointer(void *pointer) 
{
    if (pointer == NULL) {
        ft_putstr_fd("(nil)", 1);
        return;
    }

    write(1, "0x", 2);

    long num = (long)pointer;
    const int lONG_BYTES_COUNT = 8;
    unsigned char *p = (unsigned char *)&num + lONG_BYTES_COUNT - 1;
    int i = 0;
    while (i < lONG_BYTES_COUNT)
    {
        unsigned char byte = *p;

        int tens = byte / 16;
        int unit = byte % 16;

        if (tens > 0)
        {
            char ch = tens + '0';
            if (tens > 9) {
                ch = (tens - 10) + 'a';
            }

            write(1, &ch, 1);
        }

        if (unit > 0)
        {
            char ch = unit + '0';
            if (unit > 9) {
                ch = (unit - 10) + 'a';
            }

            write(1, &ch, 1);
        }
        i++;
        p--;
    }
}

void ft_putInt_hex(int num, int isUpper)
{
    const int INTEGER_BYTES_COUNT = 4;
    char *p = (char *)&num + INTEGER_BYTES_COUNT - 1;
    int i = 0;
    while (i < INTEGER_BYTES_COUNT)
    {
        unsigned char byte = *p;

        int tens = byte / 16;
        int unit = byte % 16;

        if (tens > 0)
        {
            char ch = tens + '0';
            if (tens > 9) {
                if (isUpper)
                    ch = (tens - 10) + 'A';
                else
                    ch = (tens - 10) + 'a';
            }

            write(1, &ch, 1);
        }

        if (unit > 0)
        {
            char ch = unit + '0';
            if (unit > 9) {
                if (isUpper)
                    ch = (unit - 10) + 'A';
                else
                    ch = (unit - 10) + 'a';
            }

            write(1, &ch, 1);
        }
        i++;
        p--;
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