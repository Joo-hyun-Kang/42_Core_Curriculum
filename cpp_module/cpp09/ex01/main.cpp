#include "RPN.hpp"

int	main(int argc, char **argv)
{
	std::stack<int>	stackMain;

	if (argc != 2) {
		std::cout << "Error: invalid argument" << std::endl;
		exit(1);
	}
	stackMain = pileStack(argv[1]);
	std::cout << stackMain.top() << std::endl;
}
