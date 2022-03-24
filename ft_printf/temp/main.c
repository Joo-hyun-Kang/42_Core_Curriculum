#include <stdio.h>
#include "ft_printf.h"

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

    {
        //기타 예외 출력 검사
        printf("%d %s %z", 100, "100", 100);
        ft_printf("%d %s %z", 100, "100", 100);
    }

}