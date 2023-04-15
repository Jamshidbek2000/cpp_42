#include "../includes/PhoneBook.hpp"

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

bool		is_str_digits(const std::string& str)
{
	unsigned int	size;

	size = str.size();
	for (size_t i = 0; i < size; i++)
	{
		if (std::isdigit(str.at(i)) == 0)
			return (false);
	}
	return (true);
}

int	str_to_int(std::string str)
{
	std::stringstream ss(str);
	int num;
	ss >> num;
	return (num);
}

std::string	int_to_str(int num)
{
	std::stringstream ss;
	ss << num;
	return (ss.str());
}