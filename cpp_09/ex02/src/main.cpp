#include <exception>
#include <sstream>
#include "../include/PmergeMe.hpp"

bool isNum(std::string &str) {
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str.at(i) == ' ') continue;
		if (str.at(i) < '0' || str.at(i) > '9') return false;
	}
	return true;
}

bool isGoodInput(int argc, char **argv) {
	if (argc < 2) return false;
	for (int i = 1; i < argc; i++) {
		std::string num(argv[i]);
		if (isNum(num) == false) return false;
	}
	return true;
}

int main(int argc, char **argv) {
	std::vector<int> vec;
	std::deque<int> deq;
	int num;

	try {
		if (isGoodInput(argc, argv) == false) {
			std::cout << RED_TXT << "Wrong Input!" << DEFAULT_TXT << std::endl;
			return 0;
		}
		for (int i = 1; i < argc; i++) {
			std::stringstream s(argv[i]);
			while (s >> num) {
				vec.push_back(num);
				deq.push_back(num);
			}
		}
		PmergeMe s(vec, deq);
		s.sort();

	} catch (const std::exception &e) {
		std::cerr << RED_TXT << e.what() << DEFAULT_TXT << std::endl;
	}

	return 0;
}