#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class AForm
{
private:
	const std::string _name;
	const int _signGrade;
	const int _execGrade;
	bool _signed;
	const std::string _target;

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
	AForm();
	AForm(std::string newName, int signGrade, int execGrade, std::string target);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	void beSigned(Bureaucrat &signer);
	std::string getName() const;
	std::string getTarget() const;
	int getGradeToSign() const;
	bool getIsSigned() const;
	int getExecGrade() const;
	bool canExec(Bureaucrat const &executer) const;
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm &obj);
