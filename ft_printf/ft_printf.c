#include "ft_printf.h"

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