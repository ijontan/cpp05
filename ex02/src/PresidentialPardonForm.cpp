#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

/***********************************
 * Constructors
 ***********************************/

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Pardon Form", 25, 5)
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
}
