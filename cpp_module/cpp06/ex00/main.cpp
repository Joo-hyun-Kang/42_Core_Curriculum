#include <iostream>
#include <cstdlib>
#include "Convert.hpp"


#include "Parser.hpp"
#include <limits>

int main(int ac, char **av)
{




//     This literal must belong to one of the following a scalar types:
// char, int, float or double. Except for char parameters, only the decimal notation will be
// used. ==> 들어올 수 있는 매개변수

	Convert c;

	if (ac != 2)
	{
		std::cout << "argument count is not 2" << std::endl;
		return (1);
	}	
	c.setValue(av[1]);
    std::cout << c << std::endl;

	// c.setValue("1212223");
	// std::cout << c << std::endl;

    // c.setValue("-1213f");
	// std::cout << c << std::endl;

    // c.setValue("18446744073709551615");
	// std::cout << c << std::endl;

    // unsigned long long ull = std::numeric_limits<unsigned long long>::max();
    // double val_double = static_cast<double>(ull);
    
    // std::cout << ull << std::endl;
    // std::cout << val_double << std::endl;

    Parser a("1234");
    std::cout << a.getValue() << std::endl;
    
    a = a;
    std::cout << a.getValue() << std::endl;


    return 0;
}