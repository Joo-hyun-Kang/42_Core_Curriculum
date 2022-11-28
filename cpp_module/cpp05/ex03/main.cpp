#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat b("b", 5);
    Intern i;

    Form* rrf;
    rrf = i.makeForm("shrubbery creation", "Bender");
    if (rrf == NULL)
    {
        return 1;
    }

    b.signForm(*rrf);

    std::cout << *rrf << std::endl;

    b.executeForm(*rrf);		

    delete rrf;

	return (0);
}
