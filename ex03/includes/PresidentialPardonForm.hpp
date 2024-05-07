#pragma once
#include <AForm.hpp>
#include <string>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	void execute(Bureaucrat const &executor) const;

private:
};
