#include "Bureaucrat.hpp"

int main(void)
{
    {
        std::cout << "Test : low init!" << std::endl;

        try
        {
            Bureaucrat b1("low init", 160);
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "Test : high init!" << std::endl;

        try
        {
            Bureaucrat b1("high init", 0);
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "Test : increament!" << std::endl;

        try
        {
            Bureaucrat b1("increament", 150);
            while (b1.getGrade() >= 0)
            {
                b1.incrementGrade();
            }
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "Test : decrement!" << std::endl;

        try
        {
            Bureaucrat b1("decrement", 1);
            while (b1.getGrade() <= 150)
            {
                b1.decrementGrade();
            }
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    Bureaucrat b("bbb", 40);
    std::cout << b << std::endl;

    return 0;
}