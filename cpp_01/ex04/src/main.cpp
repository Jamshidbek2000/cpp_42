#include "../includes/main.h"

int	main(int argc, char **argv)
{
	std::ifstream 	ifs;
	std::ofstream	ofs;
	std::string		remove;
	std::string		add;

	if (input_check(argc, argv) == false)
		return (1);
	else if (file_to_ifstream(std::string(argv[1]), ifs) == false)
		return (2);
	else if (file_to_ofstream(std::string(argv[1]).append(".replace"), ofs) == false)
	{
		ifs.close();
		return (3);
	}
	remove = std::string(argv[2]);
	add = std::string(argv[3]);
	if (replace_str_from_ifstream(ifs, ofs, remove, add) == false)
	{
		ifs.close();
		ofs.close();
		return (4);
	}
	ifs.close();
	ofs.close();
	return (0);
}
