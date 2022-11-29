#include "Parser.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "give me input!" << std::endl;
		return 1;
	}

    Parser parser(argv[1]);
    parser.parseValue();
    parser.printValue();

    return 0;
}