#pragma once
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	void execute(Bureaucrat const &executor) const;

private:
};
