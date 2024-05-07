#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

/***********************************
 * Constructors
 ***********************************/

const std::string Intern::_formTypes[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation",
};

Intern::Intern(void)
{
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return *this;
}

/***********************************
 * Destructors
 ***********************************/

Intern::~Intern(void)
{
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *form = 0;
	int i = 0;
	for (i = 0; i < 3; i++)
		if (_formTypes[i] == name)
			break;

	switch (i)
	{
	case 0:
		form = new PresidentialPardonForm(target);
		break;
	case 1:
		form = new RobotomyRequestForm(target);
		break;
	case 2:
		form = new ShrubberyCreationForm(target);
		break;
	default:
		std::cerr << "cannot create form: " << name << std::endl;
	}
	return form;
}
