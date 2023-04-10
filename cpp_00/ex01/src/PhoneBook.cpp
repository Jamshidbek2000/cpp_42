#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nb_contacts(0), _index_to_add(0){}
PhoneBook::~PhoneBook(void){}

Contact	PhoneBook::get_contact_at_index(const unsigned int index) const
{
	return (_contacts[index]);
}

int	PhoneBook::execute_cmd(const std::string cmd)
{
	if (cmd.compare("ADD") == 0)
		add_new_contact_from_input();
	else if (cmd.compare("SEARCH") == 0)
		std::cout << *this;
	else if (cmd.compare("EXIT") == 0)
		return (1);
	return (0);
}

void	PhoneBook::add_new_contact_from_input()
{
	_contacts[_index_to_add].set_name(get_input_to_add_contact("Enter name: "));
	_contacts[_index_to_add].set_surname(get_input_to_add_contact("Enter surname: "));
	_contacts[_index_to_add].set_nickname(get_input_to_add_contact("Enter nickname: "));
	_contacts[_index_to_add].set_secret(get_input_to_add_contact("Enter darkest secret: "));
	_contacts[_index_to_add].set_phone_number(get_input_to_add_contact("Enter phone number: "));
	_index_to_add = (_index_to_add + 1) % MAX_CONTACTS;
	if (_nb_contacts < MAX_CONTACTS)
		_nb_contacts++;
}

void	PhoneBook::print_contacts() const
{
	for (size_t i = 0; i < _nb_contacts; i++)
		std::cout << _contacts[i] << std::endl;	
}

unsigned int	PhoneBook::get_nb_contacts() const
{
	return (_nb_contacts);
}

void	PhoneBook::print_cell(std::string str) const
{
	int	len = str.size();

	if (len > 10)
		std::cout << str.substr(1, 9) << "." << "|";
	else if (len == 10)
		std::cout << str << "|";
	else
		std::cout << std::string(10 - len, ' ') << str << "|";

}

// OPERATOR OVERWRITING
std::ostream& operator<<(std::ostream& os, const PhoneBook& phonebook)
{
	Contact	c;

	os << std::string(45, '-') << std::endl;
	for (size_t i = 0; i < phonebook.get_nb_contacts(); i++)
	{
		c = phonebook.get_contact_at_index(i);
		os << "|";
		phonebook.print_cell(std::to_string(i));
		phonebook.print_cell(c.get_name());
		phonebook.print_cell(c.get_surname());
		phonebook.print_cell(c.get_nickname());
		os << std::endl;
	}
	os << std::string(45, '-') << std::endl;
	return (os);
}

// STATIC FUNCTIONS

void	PhoneBook::get_user_input(std::string &input)
{
	getline(std::cin, input);
	if (input.empty() == false)
		str_trim(input, " \t");
	if (input.empty() == false)
		str_to_upper(input);
}

bool	PhoneBook::is_wrong_cmd(const std::string &cmd)
{
	if (cmd.compare("ADD") == 0)
		return (false);
	else if (cmd.compare("SEARCH") == 0)
		return (false);
	else if (cmd.compare("EXIT") == 0)
		return (false);
	return (true);
}

void	PhoneBook::print_wrong_cmd_msg(void)
{
	std::cout << "\t\t\tWRONG COMMAND!!!" << std::endl;
}

std::string	PhoneBook::get_input_to_add_contact(const std::string &prompt)
{
	std::string	result;

	result = "";
	while (result.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, result);
		str_trim(result, " \t");
		if (result.empty())
			std::cout << "\t\t\tFIELD CANNOT BE EMPTY!" << std::endl;
	}
	return (result);
}
