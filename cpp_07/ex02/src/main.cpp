#include "../include/Array.hpp"

#define MAX_VAL 750

void doubleExample() {
	std::cout << YELLOW_TXT << "\t\t\tDOUBLE EXAMPLE" << DEFAULT_TXT << std::endl;
	try {
		Array<double> dblArray(5);

		dblArray[0] = 3.14;
		dblArray[1] = 4.14;
		dblArray[2] = 5.14;
		dblArray[3] = 6.14;
		dblArray[4] = 7.14;
		// dblArray[5] = 8.14;

		for (unsigned int i = 0; i < dblArray.size(); i++) {
			std::cout << GREEN_TXT << dblArray[i] << std::endl << DEFAULT_TXT;
		}
		std::cout << std::endl;

		const Array<double> arr2 = dblArray;
		std::cout << GREEN_TXT << arr2[0] << DEFAULT_TXT << std::endl;
		// arr2[0] = 0.1;

	} catch (std::exception& err) {
		std::cerr << RED_TXT << err.what() << DEFAULT_TXT << std::endl;
	}
}

void stringExample() {
	std::cout << YELLOW_TXT << "\t\t\tSTRING EXAMPLE" << DEFAULT_TXT << std::endl;

	Array<std::string>* strArray = NULL;

	try {
		strArray = new Array<std::string>(4);

		(*strArray)[0] = "I ";
		(*strArray)[1] = "am ";
		(*strArray)[2] = "on ";
		(*strArray)[3] = "heap ";
		// (*strArray)[4] = "!";

		for (unsigned int i = 0; i < strArray->size(); i++) {
			std::cout << GREEN_TXT << (*strArray)[i] << std::endl << DEFAULT_TXT;
		}
		std::cout << std::endl;

	} catch (std::exception& err) {
		std::cerr << RED_TXT << err.what() << DEFAULT_TXT << std::endl;
	}
	delete strArray;
}

void emptyArrayExample() {
	std::cout << YELLOW_TXT << "\t\t\tEMPTY ARRAY EXAMPLE" << DEFAULT_TXT << std::endl;
	try {
		Array<int> arr(0);
		arr[0] = 1;
	} catch (std::exception& err) {
		std::cerr << RED_TXT << err.what() << DEFAULT_TXT << std::endl;
	}
}

void test42() {
	std::cout << YELLOW_TXT << "\t\t\tTEST 42" << DEFAULT_TXT << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return;
		}
	}
	try {
		numbers[-2] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete[] mirror;  //
}
int main() {
	doubleExample();
	stringExample();
	emptyArrayExample();
	test42();

	// system("leaks array");
	return 0;
}
