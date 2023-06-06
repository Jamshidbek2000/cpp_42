#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

void	shrubberyCreationFormTest()
{
	std::cout << YELLOW_TXT
			<< "\t\t\tshrubberyCreationFormTest EXAMPLE"
			<< DEFAULT_TXT << std::endl;
	try
	{
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		ShrubberyCreationForm	form("tree_1");
		ross.signForm(form);
		form.execute(harvey);
		form.execute(ross);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_TXT
				<< e.what()
				<< DEFAULT_TXT << std::endl;
	}
}

void	RobotomyRequestFormTest()
{
	std::cout << YELLOW_TXT
			<< "\t\t\tRobotomyRequestFormTest EXAMPLE"
			<< DEFAULT_TXT << std::endl;
	try
	{
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		RobotomyRequestForm	form("AutomativeWork");
		ross.signForm(form);
		harvey.signForm(form);
		form.execute(harvey);
		form.execute(ross);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_TXT
				<< e.what()
				<< DEFAULT_TXT << std::endl;
	}
}

void	PresidentialPardonFormTest()
{
	std::cout << YELLOW_TXT
			<< "\t\t\tPresidentialPardonFormTest EXAMPLE"
			<< DEFAULT_TXT << std::endl;
	try
	{
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		PresidentialPardonForm	form("Francesco");
		ross.signForm(form);
		harvey.signForm(form);
		form.execute(harvey);
		form.execute(ross);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_TXT
				<< e.what()
				<< DEFAULT_TXT << std::endl;
	}
}

int	main()
{
	shrubberyCreationFormTest();
	RobotomyRequestFormTest();
	PresidentialPardonFormTest();

	return 0;
}