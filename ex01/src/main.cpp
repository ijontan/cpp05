
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	Bureaucrat bureaucrat("jonny");
	Form form("form1", 70);

	std::cout << bureaucrat;

	try
	{
		bureaucrat.decrement();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e;
	}

	std::cout << bureaucrat;

	try
	{
		for (int i = 0; i < 150; i++)
			bureaucrat.increment();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e;
	}

	std::cout << bureaucrat;

	return 0;
}
