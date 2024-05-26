
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\033[42;1mTest 1:\033[0m exec unsigned" << std::endl;
	{
		Bureaucrat bureaucrat("jonny");
		Form form1("ok1", 100);
		Form form2("ok2", 1);
		Form form3("ok3", 50);

		bureaucrat.setGrade(25);
		bureaucrat.signForm(form1);
		bureaucrat.signForm(form2);
		bureaucrat.signForm(form3);
		bureaucrat.setGrade(1);
		bureaucrat.signForm(form2);
	}
	return 0;
}
