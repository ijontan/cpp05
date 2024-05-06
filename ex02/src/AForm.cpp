#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

AForm::AForm()
	: _name("AForm"), _signGrade(150), _execGrade(150), _signed(false)
{
}

AForm::AForm(std::string newName, int signGrade, int execGrade)
	: _name(newName), _signGrade(signGrade), _execGrade(execGrade),
	  _signed(false)
{
	if (signGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signGrade(other._signGrade),
	  _execGrade(other._execGrade), _signed(other._signGrade)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &other)
{
	_signed = other._signed;
	_lastSigned = other._lastSigned;
	return *this;
}

void AForm::beSigned(Bureaucrat &signer)
{
	_lastSigned = &signer;
	if (signer.getGrade() <= _signGrade)
		_signed = true;
}

std::string AForm::getName() const
{
	return _name;
}
int AForm::getGradeToSign() const
{
	return _signGrade;
}
bool AForm::getIsSigned() const
{
	return _signed;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

bool AForm::canExec(Bureaucrat const &executer) const
{
	if (!_signed || executer.getGrade() > _execGrade)
		return false;
	return true;
}

std::ostream &operator<<(std::ostream &os, AForm &obj)
{
	os << "AForm " << obj.getName() << "that requires grade "
	   << obj.getGradeToSign() << " to sign is "
	   << (obj.getIsSigned() ? "Signed." : "not Signed.") << std::endl;
	return os;
}
