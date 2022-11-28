#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : Form(other)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    setSigned(other.getIsSigned());
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkFormStatus(executor);
	
    srand(time(NULL));
	int randomValue = (rand() % 2); 

	std::cout << "drilling noises : dr~~ drill dr~~ drill~" << std::endl;

	if (randomValue == 1)
	{
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << getName() << " Failed to transform to be robotomized" << std::endl;
	}
}
