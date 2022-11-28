#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : Form(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : Form(other)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    setSigned(other.getIsSigned());
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkFormStatus(executor);
    executeHelper();
}

void PresidentialPardonForm::executeHelper() const
{
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}