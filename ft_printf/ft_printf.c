#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>
#include "libft.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
    size_t  count;
    int     data;

    // "%c %d" 
    // 문자열을 돌면서 %가 아닐 때 그냥 출력
    // 문자열을 돌면서 %일 때 것을 찾아내고
    // 그리고 c, d,인지 확인
    // 아니면 그냥 %출력하고

    // va strat(ap, 문자열의 길이) -> 그 다음에 어디 스택에 위치하는 지
    // va argc (ap) -> 얼만큼 읽어올 건지
    // va end -> 끝내면 됌

    // 세가지 기능이 있음
    // 1개는 문자열 돌면서 길이 구하기
    // 다른 하나는 문자열 출력하기
    // 먼저 문자열 길이를 구해야 거기에서 빼오니까 이건 어쩔 수 없구
    // 문자열 출력하기 일 때는 "123%s"일 때
    // 123 한 글자씩 출력하고 그리고 %가 들어오면 체크하고
    // 해당 글자를 출력할 지 이게 맞네..

    //assert(format != NULL);

    count = ft_strlen(format);

    va_start(ap, format);
    {   
        while (*format != '\0')
        {
            if (*format == '%')
            {
                if (*(format + 1) == 'c')
                {
                    data = va_arg(ap, int);
                    //write는 문자만 출력가능요..
                    //write(1, &data, 4);
                    format++;
                    format++;
                    continue;
                }
                else if (*(format + 1) == 'd')
                {
                    data = va_arg(ap, int);
                    //write는 문자만 출력가능요..
                    //write(1, &data, 4);
                    format++;
                    format++;
                    continue;
                }
                else
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

int main(void)
{
    
    //printf("1234 %d", 1);
    //ft_printf("1234 %d", 1);

}