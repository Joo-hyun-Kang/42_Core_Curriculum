#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //mine
    for (int i = 0; i < 5; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << mirror[i] << " ";
    }
    std::cout << std::endl;


    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        //mine
        for (int i = 0; i < 5; i++)
        {
            std::cout << test[i] << " ";
        }
        std::cout << std::endl;

        //Const Test
        const Array<int> test2(tmp);
    
        test[0] = 4;
        // test2[0] = 5;

        for (int i = 0; i < 5; i++)
        {
            std::cout << test[i] << " ";
        }
        std::cout << std::endl;

        //=Test
        test = test2;
        for (int i = 0; i < 5; i++)
        {
            std::cout << test[i] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    //mine
    if (numbers.size() == MAX_VAL)
    {
        std::cout << "size() is ok!" << std::endl;
    }

    //system("leaks array");

    return 0;
}