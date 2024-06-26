#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

/***********************************
 * Constructors
 ***********************************/

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Request Form", 72, 45, target)
{
	srand(time(NULL));
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
	if (!canExec(executor))
		return;
	if (rand() > RAND_MAX / 2)
		std::cout << getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}
