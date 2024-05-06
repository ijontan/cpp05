#pragma once
#include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	void execute(Bureaucrat const &executor) const;

private:
};
