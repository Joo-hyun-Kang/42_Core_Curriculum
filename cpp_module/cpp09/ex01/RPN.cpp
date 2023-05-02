#include "RPN.hpp"

std::stack<int>	pileStack(char *raw) {
	std::stack<int> stackMain;
	int		a;
	int		b;
	char	op;
	int		i = 0;

	while (i < (int)strlen(raw)) {
		if (isdigit(raw[i])) {
			stackMain.push(raw[i++] - '0');
			continue;
		} else if (raw[i] == '+' || raw[i] == '-' || raw[i] == '*' || raw[i] == '/') {
			if (stackMain.size() < 2) {
				std::cout << "Error" << std::endl;
				exit(1);
			}
			op = raw[i];
			b = stackMain.top();
			stackMain.pop();
			a = stackMain.top();
			stackMain.pop();
			if (op == '+') {
				a += b;
			} else if (op == '-') {
				a -= b;
			} else if (op == '*') {
				a *= b;
			} else if (op == '/') {
				a /= b;
			}
			stackMain.push(a);
		} else if (raw[i] != ' ') {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		i++;
	}
	if (stackMain.size() != 1) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	return stackMain;
}
