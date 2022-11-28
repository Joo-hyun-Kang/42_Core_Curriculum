#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    {
        std::cout << "Test : low init!" << std::endl;

        try
        {
            Form f1("low init", 160, 1);
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
            Form b1("high init", 1, 0);
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "Test : Form sign!" << std::endl;

        Bureaucrat b("b", 100);
        Form f("form", 30, 30);
        b.signForm(f);
    }

    Form f("form", 40, 30);
    Bureaucrat b("b", 40);
    b.signForm(f);
    std::cout << f << std::endl;

    return 0;
}