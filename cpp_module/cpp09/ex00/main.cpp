#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::pair<std::string, float> > vec;

	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	vec = readFile();
	calculateInput(vec, argv[1]);

	return 0;
}
