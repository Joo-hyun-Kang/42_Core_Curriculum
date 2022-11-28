#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();
	void executeHelper() const;
	
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

    virtual void execute(Bureaucrat const &executor) const;

};

#endif
