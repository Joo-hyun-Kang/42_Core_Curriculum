#include "RPN.hpp"

int	main(int argc, char **argv)
{
	std::stack<int>	stack;

	if (argc != 2) {
		std::cout << "Error: invalid argument" << std::endl;
		exit(1);
	}
	stack = calculate(argv[1]);
	std::cout << stack.top() << std::endl;
}
