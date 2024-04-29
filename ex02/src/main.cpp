
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "test 1: " << std::endl;
	{
		Bureaucrat bureaucrat("jonny");
		PresidentialPardonForm form;

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
	}
	{

	}

	return 0;
}
