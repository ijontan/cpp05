#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

Form::Form() : name("Form"), gradeToSign(150), isSigned(false)
{
}

Form::Form(std::string newName, int grade)
	: name(newName), gradeToSign(grade), isSigned(false)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form &other)
	: name(other.name), gradeToSign(other.gradeToSign),
	  isSigned(other.gradeToSign)
{
	(void)other;
}

Form::~Form()
{
}

Form &Form::operator=(Form &other)
{
	(void)other;
	return *this;
}

void Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() <= gradeToSign)
		isSigned = true;
}

std::string Form::getName()
{
	return name;
}
int Form::getGradeToSign()
{
	return gradeToSign;
}
bool Form::getIsSigned()
{
	return isSigned;
}

std::ostream &operator<<(std::ostream &os, Form &obj)
{
	os << "Form " << obj.getName() << "that requires grade "
	   << obj.getGradeToSign() << " to sign is "
	   << (obj.getIsSigned() ? "Signed." : "not Signed.") << std::endl;
	return os;
}

