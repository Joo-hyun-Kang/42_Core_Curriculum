#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static int	ft_isspace(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
	{
		return (1);
	}
	return (0);
}



// 후조건: 올바른 숫자형 문자열이 들어있는지 검증
int ft_verify_argv(char *str)
{
	int	sign;
	
	while (ft_isspace(*str))
	{
		str++;
	}
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
	}
	str++;
	if (*str == '+' || *str == '-')
	{
		return (false);
	}

}


/*
 * 선조건 : 숫자로 된 문자열
   - 처음에는 공백이 있어도 됌
   - 중간에 공백이 없어야 함 : 예외 시 공백 앞 숫자까지
   - 부호는 단 1개만 와야 함 : 예외 시 0
   - 8비트 표현 범위 내여야 함 : 예외 시 양수일 때 1, 음수일 떄 -1
 * 후조건 : 4비트 표현 범위 내 정수
 */
int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		if (result > 9223372036854775807 && sign == 1)
			return (-1);
		if (result > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}
	return ((int)(sign * result));
}