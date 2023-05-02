#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::pair<std::string, float> > data;
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}
	data = readData();
	operateInput(data, argv[1]);
	return 0;
}
