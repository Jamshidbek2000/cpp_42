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



// string by default does't include '\0'.
// So do not compare (str.at(i) != '\0').
// Use str.size() or str.length() instead

void	str_to_upper(std::string &str)
{
	unsigned int	size;

	size = str.size();
	for (unsigned int i = 0; i < size; i++)
		str[i] = std::toupper(str.at(i));
}

std::string	get_str_in_uppercase(const std::string str)
{
	std::string		result(str.size(), ' ');
	unsigned int	size;

	size = str.size();
	for (unsigned int i = 0; i < size; i++)
		result[i] = std::toupper(str.at(i));
	return (result);
}

void	str_trim(std::string &str,const char char_to_trim)
{
	str.erase(0, str.find_first_not_of(char_to_trim));
	str.erase(str.find_last_not_of(char_to_trim) + 1);
}

void	str_trim(std::string &str,const std::string chars_to_trim)
{
	unsigned long	start, end;

	start = str.find_first_not_of(chars_to_trim);
	end = str.find_last_not_of(chars_to_trim);
	if (start == std::string::npos || end == std::string::npos)
		str.clear();
	else
		str = str.substr(start, end - start + 1);
}
