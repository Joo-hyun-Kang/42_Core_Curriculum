#include "easyfind.hpp"

int main(void) {
    std::vector<int> vector;   
	std::deque<int> deque;
	std::list<int> list;

	for (int i = 0; i < 10; i++)
	{
		vector.push_back(i);
		deque.push_back(i);
		list.push_back(i);
	}

    std::cout << "vector++++++++++++" << std::endl;
    try
    {
        std::vector<int>::iterator it;

        it = easyfind(vector, 8);
        std::cout << *it << std::endl;

        it = easyfind(vector, 100);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "deque++++++++++++" << std::endl;
    try
    {
        std::deque<int>::iterator it;

        it = easyfind(deque, 10);
        std::cout << *it << std::endl;

        it = easyfind(deque, 100);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "list++++++++++++" << std::endl;
    try
    {
        std::list<int>::iterator it;

        it = easyfind(list, 1);
        std::cout << *it << std::endl;

        it = easyfind(list, 100);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    std::vector<int> vector2;

    for (int i = 0; i < 5; i++)
	{
		vector2.push_back(1);
	}

    std::cout << "vector2++++++++++++" << std::endl;
    try
    {
        std::vector<int>::iterator it;

        it = easyfind(vector2, 1);
        std::cout << *it << std::endl;

        std::vector<int>::iterator it2 = vector2.begin();

        if (it2 == it)
        {
            std::cout << "same!" << std::endl;
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //system("leaks easyfind");

	return (0);
}