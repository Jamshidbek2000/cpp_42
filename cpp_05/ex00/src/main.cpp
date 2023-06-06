#include "../include/Bureaucrat.hpp"

void	wrong_initialization()
{
	std::cout << YELLOW_TXT
			<< "\t\t\tExample 1"
			<< DEFAULT_TXT << std::endl;
	try
	{
		Bureaucrat	zsolt;
		Bureaucrat	john("John", 1);
		Bureaucrat	oliver(john);

		zsolt = oliver;

		std::cout << john << oliver;
		Bureaucrat	anna("Anna", 151);
		Bureaucrat	emma("Emma", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_TXT
				<< e.what()
				<< DEFAULT_TXT << std::endl;
	}
}

void	wrong_incrementGrade()
{
	std::cout << YELLOW_TXT
			<< "\t\t\tExample 2"
			<< DEFAULT_TXT << std::endl;
	try
	{
		Bureaucrat	pareto("Pareto", 10);

		while (true)
		{
			std::cout << pareto;
			pareto.incrementGrade();
		}
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
	wrong_initialization();
	wrong_incrementGrade();

	return 0;
}