#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main()
{
	srand(time(NULL));

	Bureaucrat lars("Lars", 5);
	Bureaucrat hans("Hans", 45);
	Bureaucrat ellen("Ellen", 150);

	Intern tom;
	AForm* shrubbery;
	AForm* robotomy;
	AForm* pardon;
	AForm* testForm;

	shrubbery = NULL;
	robotomy = NULL;
	pardon = NULL;
	testForm = NULL;

	try
	{
		shrubbery = tom.makeForm("shrubbery creation", "home");
		robotomy = tom.makeForm("robotomy request", "Bender");
		pardon = tom.makeForm("presidential pardon", "Stephen Bannon");
		testForm = tom.makeForm("test", "test");
	}
	catch(const std::exception& error)
	{

		std::cerr << RED_TXT << error.what()
				<< DEFAULT_TXT << std::endl;
	}
	std::cout << std::endl;
	lars.executeForm(*shrubbery);
	hans.executeForm(*shrubbery);
	ellen.executeForm(*shrubbery);
	std::cout << std::endl;
	lars.signForm(*shrubbery);
	hans.signForm(*shrubbery);
	ellen.signForm(*shrubbery);
	std::cout << std::endl;
	lars.executeForm(*shrubbery);
	hans.executeForm(*shrubbery);
	ellen.executeForm(*shrubbery);
	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << std::endl;
	lars.executeForm(*pardon);
	hans.executeForm(*pardon);
	ellen.executeForm(*pardon);
	std::cout << std::endl;
	lars.signForm(*pardon);
	hans.signForm(*pardon);
	ellen.signForm(*pardon);
	std::cout << std::endl;
	lars.executeForm(*pardon);
	hans.executeForm(*pardon);
	ellen.executeForm(*pardon);
	std::cout << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
	lars.executeForm(*robotomy);
	hans.executeForm(*robotomy);
	ellen.executeForm(*robotomy);
	std::cout << std::endl;
	lars.signForm(*robotomy);
	hans.signForm(*robotomy);
	ellen.signForm(*robotomy);
	std::cout << std::endl;
	lars.executeForm(*robotomy);
	hans.executeForm(*robotomy);
	ellen.executeForm(*robotomy);

	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete testForm;

	return 0;
}