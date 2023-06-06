#include "../include/Bureaucrat.hpp"

void	wrong_initialization()
{
	std::cout << YELLOW_TXT
			<< "\t\t\tWRONG INITIALIZATION EXAMPLE"
			<< DEFAULT_TXT << std::endl;
	try
	{
		Form	tooLow("Wrong", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_TXT
				<< e.what()
				<< DEFAULT_TXT << std::endl;
	}
}

void	wrong_grade()
{
	std::cout << YELLOW_TXT
			<< "\t\t\tWRONG GRADE EXAMPLE"
			<< DEFAULT_TXT << std::endl;
	try
	{	
		Bureaucrat	ross("Ross", 50);
		Bureaucrat	harvey("Harvey", 1);

		Form	top1("A1", 5);
		Form	low1("C5", 55);
		Form	mid1("B2", 25);

		harvey.signForm(top1);
		harvey.signForm(top1);
		ross.signForm(low1);
		ross.signForm(mid1);
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
	wrong_grade();
	wrong_initialization();

	return 0;
}