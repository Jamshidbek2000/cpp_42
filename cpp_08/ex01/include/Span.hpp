#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

class Span {
   private:
	std::vector<int> vec;
	unsigned int size;

	Span();

   public:
	Span(unsigned int inputSize);
	Span(Span const& rhs);
	Span& operator=(Span const& rhs);
	~Span();

	void addNumber(int number);
	void addRange(std::vector<int>::iterator const& start, std::vector<int>::iterator const& end);

	void print() const;

	int longestSpan() const;
	int shortestSpan() const;

	class OutOfRangeException : public std::exception {
	   public:
		const char* what() const throw();
	};
	class TooLessNumbersException : public std::exception {
	   public:
		const char* what() const throw();
	};
};

#endif