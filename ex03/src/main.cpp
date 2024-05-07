/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan </var/spool/mail/itan>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:36:19 by itan              #+#    #+#             */
/*   Updated: 2024/05/07 19:36:38 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
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
	std::cout << "\033[42;1mTest 1:\033[0m test form that doesn't exist"
			  << std::endl;
	{
		Bureaucrat bureaucrat("donny");
		Intern intern;
		AForm *form = intern.makeForm("random name", "target1");
		if (form == NULL)
			goto ending1;
		bureaucrat.setGrade(1);
		form->beSigned(bureaucrat);
		form->execute(bureaucrat);
	}
ending1:

	std::cout << "\n\033[42;1mtest 2:\033[0m pres" << std::endl;
	{
		Bureaucrat bureaucrat("wonny");
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "target2");

		bureaucrat.setGrade(1);
		form->beSigned(bureaucrat);
		form->execute(bureaucrat);
	}

	std::cout << "\n\033[42;1mtest 3:\033[0m robo" << std::endl;
	{
		Bureaucrat bureaucrat("tonny");
		Intern intern;
		AForm *form = intern.makeForm("robotomy request", "target2");

		bureaucrat.setGrade(1);
		form->beSigned(bureaucrat);
		form->execute(bureaucrat);
	}

	std::cout << "\n\033[42;1mtest 4:\033[0m shru" << std::endl;
	{
		Bureaucrat bureaucrat("yonny");
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "target2");

		bureaucrat.setGrade(1);
		form->beSigned(bureaucrat);
		form->execute(bureaucrat);
	}

	return 0;
}
