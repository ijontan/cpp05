
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdio>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <streambuf>
#include <string>
#include <unistd.h>

int main()
{
	std::cout << "\033[42;1mTest 1:\033[0m exec unsigned" << std::endl;
	{
		Bureaucrat bureaucrat("jonny");
		PresidentialPardonForm form1("ok");
		RobotomyRequestForm form2("ok");
		ShrubberyCreationForm form3("ok");

		bureaucrat.setGrade(1);
		bureaucrat.executeForm(form1);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form3);
	}
	std::cout << "\n\033[42;1mtest 2:\033[0m sign not high enough" << std::endl;
	{
		Bureaucrat bureaucrat("conny");
		PresidentialPardonForm form1("ok");
		RobotomyRequestForm form2("ok");
		ShrubberyCreationForm form3("ok");

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
		PresidentialPardonForm form1("ok");
		RobotomyRequestForm form2("ok");
		ShrubberyCreationForm form3("ok");

		bureaucrat.setGrade(145);
		bureaucrat.signForm(form3);
		bureaucrat.setGrade(72);
		bureaucrat.signForm(form2);
		bureaucrat.setGrade(25);
		bureaucrat.signForm(form1);
	}
	std::cout << "\n\033[42;1mtest 4:\033[0m exec not high enough" << std::endl;
	{
		Bureaucrat bureaucrat("fonny");
		PresidentialPardonForm form1("ok");
		RobotomyRequestForm form2("ok");
		ShrubberyCreationForm form3("ok");

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
	std::cout << "\n\033[42;1mtest 5:\033[0m exec high enough" << std::endl;
	{
		Bureaucrat bureaucrat("fonny");
		PresidentialPardonForm form1("ok");
		RobotomyRequestForm form2("ok");
		ShrubberyCreationForm form3("ok");

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
		unsigned long number_of_test = 100000;
		std::streambuf *bufftmp = std::cout.rdbuf();
		std::ofstream file("file.tmp");
		if (file.fail())
			goto ending;
		std::cout.rdbuf(file.rdbuf());

		Bureaucrat bureaucrat("nonny");
		RobotomyRequestForm form("ok");
		bureaucrat.setGrade(1);
		bureaucrat.signForm(form);
		for (unsigned long i = 0; i < number_of_test; i++)
			bureaucrat.executeForm(form);
		std::cout.rdbuf(bufftmp);
		file.close();

		std::ifstream file1("file.tmp");
		std::string line;
		unsigned long number_failed = 0;
		unsigned long total = 0;
		float percent;
		while (std::getline(file1, line))
		{
			if (line.find("failed") != std::string::npos)
				++number_failed;
			++total;
		}
		percent = (float)number_failed / total;
		std::cout << "number of test: " << total << ", percentages: " << percent << std::endl;
		file1.close();
	}
ending:

	return 0;
}
