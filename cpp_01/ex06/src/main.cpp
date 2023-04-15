#include "../includes/Harl.hpp"

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cout << "\t\tWrong nuber of arguments!" << std::endl;
		std::cout << "\t\tProgram accepts 1 argument only!" << std::endl;
		return (1);
	}
	Harl	harl;
	
	harl.complain(std::string(argv[1]));
	return (0);
}