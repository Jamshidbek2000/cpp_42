#include <exception>

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED_TXT << "Error: could not open file." << DEFAULT_TXT << std::endl;
		return 0;
	}
	std::string fileName(argv[1]);

	try {
		BitcoinExchange btc(fileName);
		btc.run();

	} catch (const std::exception &err) {
		std::cerr << RED_TXT << err.what() << DEFAULT_TXT << std::endl;
	}

	return 0;
}