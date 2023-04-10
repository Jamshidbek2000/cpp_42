#include <iostream>

// string by default does't include '\0'.
// So do not compare (str.at(i) != '\0').
// Use str.size() or str.length() instead
static	std::string	string_to_upper(std::string str)
{
	unsigned int	size;

	size = str.size();
	for (unsigned int i = 0; i < size; i++)
		str[i] = std::toupper(str.at(i));
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
		std::cout << string_to_upper(argv[i]);
	std::cout << std::endl;
	return (0);
}
