#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

/***********************************
 * Constructors
 ***********************************/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Request Form", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &rhs)
{
	AForm::operator=(rhs);
	return *this;
}

/***********************************
 * Destructors
 ***********************************/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
}
