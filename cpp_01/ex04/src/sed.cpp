#include "../includes/main.h"

bool	input_check(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "\t\tWrong number of args!" << std::endl;
		return (false);
	}
	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]).empty())
		{
			std::cout << "\t\tInput cannot be empty!" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	file_to_ifstream(std::string file_name, std::ifstream& ifs)
{
	char	array[file_name.size() + 1];

	array[file_name.size()] = '\0';
	for (unsigned long i = 0; i < file_name.size(); i++)
		array[i] = file_name.at(i);	
	ifs.open(array);
	if (!ifs.is_open())
	{
		std::cout << "\t\tCould not open: " << file_name << std::endl;
		return (false);
	}
	return (true);
}

bool	file_to_ofstream(std::string file_name, std::ofstream& ofs)
{
	char	array[file_name.size() + 1];

	array[file_name.size()] = '\0';
	for (unsigned long i = 0; i < file_name.size(); i++)
		array[i] = file_name.at(i);
	ofs.open(array);
	if (!ofs.is_open())
	{
		std::cout << "\t\tCould not open: " << file_name << std::endl;
		return (false);
	}
	return (true);
}

void	my_str_replace(std::string& str, std::string& remove, std::string& add)
{
	int			i;
	std::string	result;

	result = "";
	i = -1;
	while (true)
	{
		i = str.find(remove);
		if (i == -1)
		{
			result.append(str);
			break;
		}
		result.append(str.substr(0, i)); // until remove_index
		result.append(add); // add word
		str.erase(0, i + remove.size()); // cut left part
	}
	str = result;
}

bool	replace_str_from_ifstream(std::ifstream &ifs, std::ofstream& ofs
								, std::string& remove, std::string& add)
{
	std::string	line;
	bool		add_new_line;

	add_new_line = false;
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		if (ifs.fail())
		{
			if (add_new_line)
				ofs << std::endl;
			return (false);
		}
		my_str_replace(line, remove, add);
		if (add_new_line == false)
			add_new_line = true;
		else
			ofs << std::endl;
		ofs << line;
		if (ofs.fail())
		{
			std::cout << "\t\tSomething went wrong when writing to output!" << std::endl;
			return (false);
		}
	}
	return (true);
}
