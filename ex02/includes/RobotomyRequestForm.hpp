#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(void);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);
	void execute(Bureaucrat const & executor) const;

private:
	
};
