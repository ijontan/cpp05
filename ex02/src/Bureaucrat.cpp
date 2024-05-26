#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string newName) : _name(newName), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(150)
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
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

void Bureaucrat::increment()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
	if (form.getIsSigned())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because bureaucrat grade too "
				  << (form.getGradeToSign() < _grade ? "low" : "high")
				  << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
	if (!form.getIsSigned())
		std::cerr << form.getName() << " is not signed" << std::endl;
	if (form.getExecGrade() < _grade)
		std::cerr << "Grade not high enough to exececute " << form.getName()
				  << std::endl;
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
