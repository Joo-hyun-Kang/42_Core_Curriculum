#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
}

Form *Intern::makeForm(std::string formType, std::string target)
{

    Form *(Intern::*fp[3])(std::string target) = {&Intern::CreateShrubberyForm, &Intern::CreateRobotomyForm, &Intern::CreatePresidentialForm};
    std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    try
    {
        for (size_t i = 0; i < 3; i++)
        {
            if (types[i] == formType)
            {
                std::cout << "Intern creates " << types[i] << std::endl;

                return (this->*fp[i])(target);
            }
        }

        throw NoFormTypeExcption();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;

        return NULL;
    }
    
    return NULL;
}

const char *Intern::NoFormTypeExcption::what(void) const throw()
{
	return "There is no Form, Please Check Form Type";
}

Form *Intern::CreateShrubberyForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

Form *Intern::CreateRobotomyForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

Form *Intern::CreatePresidentialForm(std::string target)
{
    return new PresidentialPardonForm(target);
}