#include "Span.hpp"

int main()
{
	Span span = Span(500);

    try
    {
        for (int i = 0; i < 501; i++)
        {
            span.addNumber(i * 3);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Span span2 = Span(200001);

    try
    {
        for (unsigned int i = 0; i < 200000; i++)
        {
            span2.addNumber(i * 4);
        }
        span2.addNumber(-2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
		std::cout << span2.shortestSpan() << std::endl;
		std::cout << span2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

	Span span3 = Span(40);

    std::vector<int> temp;
    temp.reserve(10);
    temp.push_back(1);
    temp.push_back(2);

    std::vector<int>::iterator it = temp.begin();
    std::vector<int>::iterator it2 = temp.end();
    std::cout << "Temp!" << std::endl;

    span3.addNumbers(it, it2);
    
    std::vector<int> copy = span3.getVector();
    for (std::vector<int>::iterator iter = copy.begin(); iter != copy.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << "Test!" << std::endl;

    Span span4(span3);
    std::vector<int> copy2 = span4.getVector();
    for (std::vector<int>::iterator iter = copy2.begin(); iter != copy2.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

	return 0;
}