#include "iter.hpp"

int main()
{
    std::string strs[5] = {"one", "two", "three", "four", "five"};
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    iter(strs, 5, print);
    std::cout << std::endl;

    iter(arr, 10, print);
    std::cout << std::endl;


    std::cout << std::endl;


    iter(strs, 5, print<std::string>);
    std::cout << std::endl;

    iter(arr, 10, print<int>);
    std::cout << std::endl;


    std::cout << std::endl;


    iter(arr, 10, multiply<int>);

    iter(arr, 10, print<int>);
    std::cout << std::endl;

    iter(arr, 10, multiply2);
    
    iter(arr, 10, print<int>);
    std::cout << std::endl;

	return (0);
}