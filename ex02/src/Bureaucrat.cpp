#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string newName) : name(newName), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(150)
{
	(void)other;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	(void)other;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::increment()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void Bureaucrat::executeForm(AForm const &form)
{
	if (!form.getIsSigned())
		std::cerr << "Form is not signed" << std::endl;
	if (form.getExecGrade() > getGrade())
		std::cerr << "Grade not high enough to exececute" << std::endl;
	form.execute(*this);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "."
	   << std::endl;
	return os;
}

std::ostream &operator<<(std::ostream &os,
						 Bureaucrat::GradeTooLowException &obj)
{
	os << obj.what() << std::endl;
	return os;
}

std::ostream &operator<<(std::ostream &os,
						 Bureaucrat::GradeTooHighException &obj)
{
	os << obj.what() << std::endl;
	return os;
}
