#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
    Form *CreateShrubberyForm(std::string target);
    Form *CreateRobotomyForm(std::string target);
    Form *CreatePresidentialForm(std::string target);

public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	Form *makeForm(std::string formType, std::string target);

	class NoFormTypeExcption : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

#endif