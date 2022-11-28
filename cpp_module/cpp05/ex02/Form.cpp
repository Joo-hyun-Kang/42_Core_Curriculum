#include "Form.hpp"

Form::Form()
	: mName("Default")
	, mIsSigned(false)
	, mToSign(150)
	, mToExecute(150)
{}

Form::Form(const std::string name, int toSign, int toExecute)
	: mName(name)
	, mIsSigned(false)
	, mToSign(toSign)
	, mToExecute(toExecute)
{
	if (toSign < 1 || toExecute < 1)
	{
		throw Form::GradeTooHighException();
	}

	if (toSign > 150 || toExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &other)
	: mName(other.mName)
	, mIsSigned(other.mIsSigned)
	, mToSign(other.mToSign)
	, mToExecute(other.mToExecute)
{}

Form &Form::operator=(const Form &other)
{
	mIsSigned = other.mIsSigned;

	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return mName;
}

bool Form::getIsSigned() const
{
	return mIsSigned;
}

int Form::getToSign() const
{
	return mToSign;
}

int Form::getToExecute() const
{
	return mToExecute;
}

void Form::setSigned(bool isSigned)
{
	mIsSigned = isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= mToSign)
	{
		mIsSigned = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

void Form::checkFormStatus(const Bureaucrat& bureaucrat) const
{
	if (mIsSigned == false)
	{
		throw NoSignFormException();
	}
	else if (bureaucrat.getGrade() > mToExecute)
	{
		throw GradeTooLowException();
	}
	
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Form: Grade out of range : Too high!";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Form: Grade out of range : Too low!";
}

const char* Form::NoSignFormException::what(void) const throw()
{
	return "the form is not signed!! check again!"; 
}

std::ostream &operator<<(std::ostream& out, const Form &form)
{
	out << "Form Name : " << form.getName() \
		<< " is Signed : " << std::boolalpha << form.getIsSigned() \
		<< " Grade to sign : " << form.getToSign() \
		<< " Grade to Execute : " << form.getToExecute();
	
	return (out);
}
