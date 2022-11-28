#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
 private:
  	PresidentialPardonForm();

 public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

    virtual void execute(Bureaucrat const &executor) const;
};

#endif
