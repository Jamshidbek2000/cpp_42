#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

class RPN {
   private:
	static std::stack<int> elements;

	RPN();
	RPN(std::string & input);
	RPN(RPN const& rhs);
	RPN& operator=(RPN const& rhs);
	~RPN();

	static bool isCorrectInput(std::string& input);
	static bool isOperator(char c);
	static bool isDigit(char c);
	static void freeStack();

   public:
	static int calculate(std::string& input);

	class WrongInputException : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif