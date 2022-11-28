#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: mName("Bureaucrat")
	, mGrade(150)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: mName(name)
    , mGrade(grade)
{
	if (mGrade < 1)
    {
		throw Bureaucrat::GradeTooHighException();
    }

	if (mGrade > 150)
    {
		throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: mName(other.mName)
	, mGrade(other.mGrade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	mGrade = other.mGrade;

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string const Bureaucrat::getName() const
{
	return mName;
}

int Bureaucrat::getGrade() const
{
	return mGrade;
}

void Bureaucrat::incrementGrade()
{
	if (mGrade == 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    --mGrade;
}

void Bureaucrat::decrementGrade()
{
	if (mGrade == 150)
    {
		throw Bureaucrat::GradeTooLowException();
    }
    ++mGrade;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw ()
{
    return "Grade out of range : Too high!";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw ()
{
    return "Grade out of range : Too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();

    return (out);
}