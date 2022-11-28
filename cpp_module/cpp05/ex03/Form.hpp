#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string mName;
	bool mIsSigned;
	const int mToSign;
	const int mToExecute;

public:
	Form();
	Form(const std::string name, int toSign, int toExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	virtual ~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getToSign() const;
	int getToExecute() const;
	void setSigned(bool isSigned);

	void beSigned(const Bureaucrat& bureaucrat);
	void checkFormStatus(const Bureaucrat& bureaucrat) const;
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};

	class NoSignFormException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream& out, const Form &form);

#endif
