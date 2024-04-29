#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
public:
	ShrubberyCreationForm(void);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);
	void execute(Bureaucrat const & executor) const;

private:
	
};

