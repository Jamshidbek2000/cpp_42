#include "../includes/PhoneBook.hpp"

static void	start_simulation(void);


int	main(int argc, char **argv)
{
	(void)argv;

	if (argc == 1)
		start_simulation();
	else
		std::cout << "phonebook does not take arguments" << std::endl;
	return (0);
}

static void	start_simulation(void)
{
	PhoneBook	phonebook;
	std::string	input_cmd;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	input_cmd = "";
	while (true)
	{
		std::cout << "You have options: 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
		PhoneBook::get_user_input(input_cmd);
		if (input_cmd.empty())
			continue;
		if (PhoneBook::is_wrong_cmd(input_cmd))
			PhoneBook::print_wrong_cmd_msg();
		else if (phonebook.execute_cmd(input_cmd) == 1)
			break;
	}
	std::cout << "You left My Awesome PhoneBook" << std::endl;
}
