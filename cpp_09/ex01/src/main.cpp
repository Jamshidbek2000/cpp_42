#include <exception>

#include "../include/RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED_TXT << "Error: wrong number of arguments passed." << DEFAULT_TXT
				  << std::endl;
		return 0;
	}
	std::string input(argv[1]);
	try {
		std::cout << BLUE_TXT << RPN::calculate(input) << DEFAULT_TXT << std::endl;
	} catch (const std::exception &err) {
		std::cerr << RED_TXT << err.what() << DEFAULT_TXT << std::endl;
	}

	return 0;
}

//  "8 9 * 9 - 9 - 9 - 4 - 1 +"

// "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
// 
// "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"