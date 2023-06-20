#include "../include/easyfind.hpp"

int main() {
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(3);

	try {
		std::vector<int>::vector::iterator it = easyfind(numbers, 3);
		std::cout << "Value found at index: " << std::distance(numbers.begin(), it) << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED_TXT << e.what() << DEFAULT_TXT << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(numbers, 6);
		std::cout << "Value found at index: " << std::distance(numbers.begin(), it) << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED_TXT << e.what() << DEFAULT_TXT << std::endl;
	}

	return 0;
}