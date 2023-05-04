#include "RPN.hpp"

std::stack<int>	calculate(char *raw) {
	std::stack<int> stack;
	int		operand1;
	int		operand2;
	char	oper;
	int		i = 0;

	while (i < (int)strlen(raw)) 
	{
		if (isdigit(raw[i])) 
		{
			stack.push(raw[i++] - '0');
			continue;
		} 
		else if (raw[i] == '+' || raw[i] == '-' || raw[i] == '*' || raw[i] == '/') 
		{
			if (stack.size() < 2) 
			{
				std::cout << "Error" << std::endl;
				exit(1);
			}
			oper = raw[i];
			operand2 = stack.top();
			stack.pop();
			operand1 = stack.top();
			stack.pop();
			if (oper == '+') 
			{
				operand1 += operand2;
			} else if (oper == '-') 
			{
				operand1 -= operand2;
			} else if (oper == '*') 
			{
				operand1 *= operand2;
			} else if (oper == '/') 
			{
				operand1 /= operand2;
			}
			stack.push(operand1);
		} 
		else if (raw[i] != ' ') 
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
		i++;
	}
	// 남아 있는 결과가 1개가 아닐 때
	if (stack.size() != 1) 
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}

	return stack;
}
