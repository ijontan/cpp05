#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

/***********************************
 * Constructors
 ***********************************/

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Pardon Form", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &src)
	: AForm(src)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &rhs)
{
	AForm::operator=(rhs);
	return *this;
}

/***********************************
 * Destructors
 ***********************************/

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!canExec(executor))
		return;
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"
			  << std::endl;
}
