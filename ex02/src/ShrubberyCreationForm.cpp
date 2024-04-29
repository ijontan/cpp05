#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

/***********************************
 * Constructors
***********************************/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Creation Form", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{

	AForm::operator=(rhs);
	return *this;
}

/***********************************
 * Destructors
***********************************/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
}
