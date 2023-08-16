#include "../include/RPN.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

std::stack<int> RPN::elements;

RPN::RPN() {}

RPN::RPN(std::string& input) {
	if (!isCorrectInput(input)) {
		throw WrongInputException();
	}
}

RPN::RPN(RPN const& rhs) { *this = rhs; }

RPN& RPN::operator=(RPN const& rhs) {
	if (this == &rhs) {
		return *this;
	}
	return *this;
}

RPN::~RPN() { freeStack(); }

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

int RPN::calculate(std::string& input) {
	int num1, num2, result;

	if (isCorrectInput(input) == false) throw WrongInputException();

	for (unsigned long i = 0; i < input.size(); i++) {
		if (input.at(i) == ' ')
			continue;
		else if (isDigit(input.at(i)))
			RPN::elements.push(static_cast<int>(input.at(i) - '0'));
		else {
			if (RPN::elements.empty()) throw WrongInputException();
			num2 = RPN::elements.top();
			RPN::elements.pop();
			if (RPN::elements.empty()) throw WrongInputException();
			num1 = RPN::elements.top();
			RPN::elements.pop();

			switch (input.at(i)) {
				case '+':
					RPN::elements.push(num1 + num2);
					break;
				case '-':
					RPN::elements.push(num1 - num2);
					break;
				case '*':
					RPN::elements.push(num1 * num2);
					break;
				case '/':
					RPN::elements.push(num1 / num2);
					break;
				default:
					freeStack();
					throw WrongInputException();
			}
		}
	}
	result = RPN::elements.top();
	freeStack();
	return result;
}

bool RPN::isCorrectInput(std::string& input) {
	int numberCount = 0;
	int operatorCount = 0;

	for (unsigned long i = 0; i < input.size(); i++) {
		if (input.at(i) == ' ')
			continue;
		else if (isDigit(input.at(i)))
			numberCount++;
		else if (isOperator(input.at(i)))
			operatorCount++;
		else
			throw WrongInputException();
		if (i + 1 != input.size() && input[i + 1] != ' ') throw WrongInputException();
	}
	return (numberCount - 1 == operatorCount);
}

void RPN::freeStack() {
	while (RPN::elements.empty() == false) RPN::elements.pop();
}

bool RPN::isOperator(char c) { return (c == '/' || c == '*' || c == '+' || c == '-'); }

bool RPN::isDigit(char c) { return (c >= '0' && c <= '9'); }

// ************************************************************************** //
//                               NESTED CLASSES                               //
// ************************************************************************** //

const char* RPN::WrongInputException::what() const throw() { return "Error: Wrong input!\n"; }