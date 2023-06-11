#include "../include/ScalarConverter.hpp"

// ************************************************************************** //
//                               PUBLIC                                       //
// ************************************************************************** //

void ScalarConverter::convert(std::string& input) {
	if (isWrongInput(input)) throw(ScalarConverter::WrongInputException());
	printChar(input);
	printInt(input);
	printFloat(input);
	printDouble(input);
}

// ************************************************************************** //
//                               PARSING                                      //
// ************************************************************************** //

void ScalarConverter::parseInput(std::string& input) {
	input = input.substr(
		input.find_first_not_of(' '),
		input.find_last_not_of(' ') - input.find_first_not_of(' ') + 1);  // trim of spaces
	if (isPseudo(input) == false && input.at(input.size() - 1) == 'f') // remove f for inff, nanf...
		input = input.substr(0, input.size() - 1);
}

bool ScalarConverter::isValidNumber(std::string& input) {
	unsigned int i = 0;
	int dotCount = 0;
	while ((input.at(i) == '+' || input.at(i) == '-') && i < input.size()) i++;
	while (i < input.size()) {
		if ((input.at(i) < '0' || input.at(i) > '9') && input.at(i) != '.') return false;
		if (input.at(i) == '.') dotCount++;
		i++;
	}
	if (dotCount > 1) return false;
	return true;
}

bool ScalarConverter::isWrongInput(std::string& input) {
	double value;

	if (input.size() == 0) return true;
	parseInput(input);
	if (input.find(' ') != std::string::npos) return true;
	if (isPseudo(input)) return false;
	if (isValidNumber(input) == false) return true;
	std::istringstream iss(input);
	if (iss >> value)
		return false;
	else
		throw(ScalarConverter::WrongInputException());
	return false;
}

bool ScalarConverter::isPseudo(std::string& input) {
	const char* pseudoliterals[4] = {"+inf", "inf", "-inf", "nan"};
	for (int i = 0; i < 4; ++i) {
		if (input.compare(pseudoliterals[i]) == 0) return true;
	}
	return false;
}

// ************************************************************************** //
//                               PRINTING                                     //
// ************************************************************************** //

bool ScalarConverter::isPrintableASCII(int i) { return (i >= 32 && i <= 126); }

void ScalarConverter::printInt(std::string& input) {
	try {
		int num = stringToInt(input);
		std::cout << "int: " << num << std::endl;
	} catch (const std::exception& e) {
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::printDouble(std::string& input) {
	try {
		double num = stringToDouble(input);
		std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
	} catch (const std::exception& e) {
		std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::printFloat(std::string& input) {
	try {
		float num = stringToFloat(input);
		std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "float: impossible" << std::endl;
	}
}

void ScalarConverter::printChar(std::string& input) {
	try {
		int asciiCode = (stringToInt(input));
		char ch = static_cast<char>(asciiCode);
		if (isPrintableASCII(asciiCode))
			std::cout << "char: '" << ch << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "char: impossible" << std::endl;
	}
}

// ************************************************************************** //
//                               CONVERTION                                   //
// ************************************************************************** //

double ScalarConverter::stringToDouble(std::string& str) {
	double value;

	std::istringstream iss(str);
	if (iss >> value)
		return value;
	else
		throw(ScalarConverter::WrongInputException());
}
int ScalarConverter::stringToInt(std::string& str) {
	int value;

	std::istringstream iss(str);
	if (iss >> value)
		return value;
	else
		throw(ScalarConverter::WrongInputException());
}

float ScalarConverter::stringToFloat(std::string& str) {
	float value;

	std::istringstream iss(str);
	if (iss >> value)
		return value;
	else
		throw(ScalarConverter::WrongInputException());
}

// ************************************************************************** //
//                               NESTED CLASS                                 //
// ************************************************************************** //

const char* ScalarConverter::WrongInputException::what() const throw() { return "Wrong Input!\n"; }
