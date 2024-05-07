#pragma once
#include "AForm.hpp"
#include <string>

class Intern
{
public:
	Intern(void);
	~Intern(void);
	Intern(const Intern &src);
	Intern &operator=(const Intern &rhs);
	AForm *makeForm(std::string name, std::string target);

private:
	static const std::string _formTypes[3];
};
