#include "../includes/PhoneBook.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

PhoneBook::PhoneBook(void) : _nb_contacts(0), _index_to_add(0){}
PhoneBook::~PhoneBook(void){}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

unsigned int	PhoneBook::get_nb_contacts() const { return (_nb_contacts); }

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

Contact	PhoneBook::get_contact_at_index(const unsigned int index) const
{
	return (_contacts[index]);
}

int	PhoneBook::execute_cmd(const std::string cmd)
{
	if (cmd.compare("ADD") == 0)
		add_new_contact_from_input();
	else if (cmd.compare("SEARCH") == 0)
		search_contact();
	else if (cmd.compare("EXIT") == 0)
		return (1);
	return (0);
}

void	PhoneBook::add_new_contact_from_input()
{
	_contacts[_index_to_add].set_name(get_input_to_add_contact("Enter name: ", TEXT));
	_contacts[_index_to_add].set_surname(get_input_to_add_contact("Enter surname: ", TEXT));
	_contacts[_index_to_add].set_nickname(get_input_to_add_contact("Enter nickname: ", TEXT));
	_contacts[_index_to_add].set_phone_number(get_input_to_add_contact("Enter phone number: ", NUMBER));
	_contacts[_index_to_add].set_secret(get_input_to_add_contact("Enter darkest secret: ", TEXT));
	std::cout << "Contact was successfully added" << std::endl;
	_index_to_add = (_index_to_add + 1) % MAX_CONTACTS;
	if (_nb_contacts < MAX_CONTACTS)
		_nb_contacts++;
}

void	PhoneBook::search_contact(void) const
{
	std::string	index;

	std::cout << *this;
	if (get_nb_contacts() == 0)
		return ;
	while (true)
	{
		std::cout << "\t\t\tPlease provide index in range: 0-" << get_nb_contacts() - 1 << std::endl;
		index = "";
		PhoneBook::get_user_input(index);
		if (is_str_digits(index) == false
			|| index.size() > int_to_str(MAX_CONTACTS).size()
			|| (long)str_to_int(index) >= (long)get_nb_contacts())
			std::cout << "\t\t\tINVALID INPUT" << std::endl;
		else
		{
			std::cout << _contacts[str_to_int(index)];
			break;
		}
	}
}

void	PhoneBook::print_contacts() const
{
	for (size_t i = 0; i < _nb_contacts; i++)
		std::cout << _contacts[i] << std::endl;	
}

// ************************************************************************** //
//                               STATIC FUNCTIONS                             //
// ************************************************************************** //

void	PhoneBook::get_user_input(std::string &input)
{
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cin.clear();
		exit(0);
	}
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

std::string	PhoneBook::get_input_to_add_contact(const std::string &prompt, InputType input_type)
{
	std::string	result;

	result = "";
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, result);
		if (std::cin.eof())
		{
			std::cin.clear();
			exit(0);
		}
		str_trim(result, " \t");
		if (result.empty())
			std::cout << "\t\t\tFIELD CANNOT BE EMPTY!" << std::endl;
		else if (input_type == NUMBER
				&& is_str_digits(result) == false)
			std::cout << "\t\t\tDIGITS ONLY" << std::endl;
		else
			break;
	}
	return (result);
}

// ************************************************************************** //
//                               OPERATOR OVERWRITING                         //
// ************************************************************************** //

void	PhoneBook::print_cell(std::string str) const
{
	if (str.size() > 10)
		std::cout << str.substr(1, 9) << "." << "|";
	else
		std::cout << std::setw(10) << std::right << str << "|";
}

void	PhoneBook::print_columns(void) const
{
	std::cout << std::string(45, '-') << std::endl << "|";
	print_cell("Index");
	print_cell("Name");
	print_cell("Surname");
	print_cell("Nickname");
	std::cout << std::endl << "|";
	std::cout << std::string(43, '-') << "|" << std::endl;
}


std::ostream& operator<<(std::ostream& os, const PhoneBook& phonebook)
{
	Contact	c;

	if (phonebook.get_nb_contacts() == 0)
		os << "\t\t\tYour phonebook is empty" << std::endl;
	else
	{
		phonebook.print_columns();
		for (size_t i = 0; i < phonebook.get_nb_contacts(); i++)
		{
			c = phonebook.get_contact_at_index(i);
			os << "|";
			phonebook.print_cell(int_to_str(i));
			phonebook.print_cell(c.get_name());
			phonebook.print_cell(c.get_surname());
			phonebook.print_cell(c.get_nickname());
			os << std::endl;
		}
		os << std::string(45, '-') << std::endl;
	}
	return (os);
}
