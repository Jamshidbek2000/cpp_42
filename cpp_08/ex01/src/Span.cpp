#include "../include/Span.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

Span::Span() {}

Span::Span(unsigned int inputSize) : size(inputSize) {}

Span::Span(Span const &rhs) : vec(rhs.vec), size(rhs.size) {}

Span::~Span() {}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Span &Span::operator=(Span const &rhs) {
  if (this != &rhs) {
    vec = rhs.vec;
    size = rhs.size;
  }
  return *this;
}

// ************************************************************************** //
//                                    MEMBER FUNCTIONS                        //
// ************************************************************************** //

void Span::addNumber(int number) {
  if (vec.size() >= size) {
    throw OutOfRangeException();
  }
  vec.push_back(number);
}

void Span::addRange(std::vector<int>::iterator const &start,
                    std::vector<int>::iterator const &end) {
  if (std::distance(start, end) + vec.size() > size)
    throw OutOfRangeException();
  vec.insert(vec.end(), start, end);
}

void Span::print() const {
  std::vector<int>::const_iterator it;
  for (it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int Span::shortestSpan() const {
  if (vec.size() <= 1) {
    throw TooLessNumbersException();
  }

  std::vector<int> sortedNumbers = vec;
  std::sort(sortedNumbers.begin(), sortedNumbers.end());

  int minSpan = sortedNumbers.back() - sortedNumbers.front();
  int span;

  for (size_t i = 1; i < sortedNumbers.size(); i++) {
    span = sortedNumbers[i] - sortedNumbers[i - 1];
    if (span < minSpan) {
      minSpan = span;
    }
  }
  return minSpan;
}

int Span::longestSpan() const {
  if (vec.size() <= 1) {
    throw TooLessNumbersException();
  }
  std::vector<int> sortedNumbers = vec;
  std::sort(sortedNumbers.begin(), sortedNumbers.end());
  return sortedNumbers.back() - sortedNumbers.front();
}

// ************************************************************************** //
//                               NESTED CLASSES                               //
// ************************************************************************** //

const char *Span::OutOfRangeException::what() const throw() {
  return "Span is full!\n";
}

const char *Span::TooLessNumbersException::what() const throw() {
  return "Not enough numbers in Span!\n";
}
