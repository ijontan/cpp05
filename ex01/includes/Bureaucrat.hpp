#pragma once

#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade is too low!";
		}
	};

	Bureaucrat();
	Bureaucrat(std::string newName);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void setGrade(int grade);
	void increment();
	void decrement();
	void signForm(Form &form);

private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &obj);
std::ostream &operator<<(std::ostream &os, Bureaucrat::GradeTooHighException &obj);
std::ostream &operator<<(std::ostream &os, Bureaucrat::GradeTooLowException &obj);

