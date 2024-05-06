
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

int main()
{
	std::cout << "\033[42;1mTest 1:\033[0m exec unsigned"
			  << std::endl;
	{
		Bureaucrat bureaucrat("jonny");
		PresidentialPardonForm form1;
		RobotomyRequestForm form2;
		ShrubberyCreationForm form3;

		bureaucrat.setGrade(1);
		bureaucrat.executeForm(form1);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form3);
	}
	std::cout << "\n\033[42;1mtest 2:\033[0m sign not high enough" << std::endl;
	{
		Bureaucrat bureaucrat("conny");
		PresidentialPardonForm form1;
		RobotomyRequestForm form2;
		ShrubberyCreationForm form3;

		bureaucrat.setGrade(146);
		bureaucrat.signForm(form3);
		bureaucrat.setGrade(73);
		bureaucrat.signForm(form2);
		bureaucrat.setGrade(26);
		bureaucrat.signForm(form1);
	}
	std::cout << "\n\033[42;1mtest 3:\033[0m sign high enough" << std::endl;
	{
		Bureaucrat bureaucrat("donny");
		PresidentialPardonForm form1;
		RobotomyRequestForm form2;
		ShrubberyCreationForm form3;

		bureaucrat.setGrade(145);
		bureaucrat.signForm(form3);
		bureaucrat.setGrade(72);
		bureaucrat.signForm(form2);
		bureaucrat.setGrade(25);
		bureaucrat.signForm(form1);
	}
	std::cout << "\n\033[42;1mtest 3:\033[0m exec not high enough" << std::endl;
	{
		Bureaucrat bureaucrat("fonny");
		PresidentialPardonForm form1;
		RobotomyRequestForm form2;
		ShrubberyCreationForm form3;

		bureaucrat.setGrade(145);
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
		bureaucrat.setGrade(72);
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.setGrade(25);
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
	}
	std::cout << "\n\033[42;1mtest 3:\033[0m exec high enough" << std::endl;
	{
		Bureaucrat bureaucrat("fonny");
		PresidentialPardonForm form1;
		RobotomyRequestForm form2;
		ShrubberyCreationForm form3;

		bureaucrat.setGrade(145);
		bureaucrat.signForm(form3);
		bureaucrat.setGrade(137);
		bureaucrat.executeForm(form3);
		bureaucrat.setGrade(45);
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.setGrade(5);
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
	}
	std::cout << "\n\033[42;1mtest 3:\033[0m test robo 50%" << std::endl;
	{
		std::ofstream file("test.tmp");
		int defout

	}

	return 0;
}
