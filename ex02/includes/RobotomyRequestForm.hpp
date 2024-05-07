#pragma once
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	void execute(Bureaucrat const &executor) const;

private:
};
