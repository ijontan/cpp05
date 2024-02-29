#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class Form
{
private:
	const std::string name;
	const int gradeToSign;
	bool isSigned;
	Bureaucrat *lastSigned;

public:
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw()
		{
			return "Grade Too High";
		}
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw()
		{
			return "Grade Too Low";
		}
	};
	Form();
	Form(std::string newName, int grade);
	Form(Form &other);
	Form &operator=(Form &other);
	~Form();
	void beSigned(Bureaucrat &signer);
	void signForm();
	std::string getName();
	int getGradeToSign();
	bool getIsSigned();
};

std::ostream &operator<<(std::ostream &os, Form &obj);
