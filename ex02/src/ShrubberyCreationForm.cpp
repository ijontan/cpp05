#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

/***********************************
 * Constructors
 ***********************************/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Creation Form", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &rhs)
{

	AForm::operator=(rhs);
	return *this;
}

/***********************************
 * Destructors
 ***********************************/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!canExec(executor))
		return;
	std::ofstream file((getTarget() + "_shrubbery").c_str());
	if (file.fail())
	{
		std::cerr << "error creating file" << std::endl;
		return;
	}
	file << "        . . .\n"
		 << "      .        .  .     ..    .\n"
		 << "   .                 .         .  .\n"
		 << "                   .\n"
		 << "                  .                ..\n"
		 << "  .          .            .              .\n"
		 << "  .            '.,        .               .\n"
		 << "  .              'b      *\n"
		 << "   .              '$    #.                ..\n"
		 << "  .    .           $:   #:               .\n"
		 << "..      .  ..      *#  @):        .   . .\n"
		 << "             .     :@,@):   ,.**:'   .\n"
		 << " .      .,         :@@*: ..**'      .   .\n"
		 << "          '#o.    .:(@'.@*\"'  .\n"
		 << "  .  .       'bq,..:,@@*'   ,*      .  .\n"
		 << "             ,p$q8,:@)'  .p*'      .\n"
		 << "      .     '  . '@@Pp@@*'    .  .\n"
		 << "       .  . ..    Y7'.'     .  .\n"
		 << "                 :@):.\n"
		 << "                .:@:'.\n"
		 << "              .::(@:.      -Sam Blumenstein-" << std::endl;
	file.close();
	std::cout << executor.getName() << " planted the shrubbery" << std::endl;
}
