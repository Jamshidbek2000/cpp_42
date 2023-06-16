#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cctype>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <new>
#include <stdexcept>
#include <string>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

template <typename T>
class Array {
   private:
	T *_array;
	unsigned int _size;

   public:
	// --------------CONSTRUCTORS---------------

	Array() : _array(NULL), _size(0) {}
	Array(unsigned int size) : _size(size) {
		if (size == 0)
			_array = NULL;
		else
			_array = new T[size]();
	}
	Array(Array const &rhs) {
		_size = rhs._size;
		if (_size == 0)
			_array = NULL;
		else {
			_array = new T[_size]();
			for (unsigned int i = 0; i < _size; i++) _array[i] = rhs._array[i];
		}
	}

	// --------------DESTRUCTORS---------------

	~Array() {
		std::cout << BLUE_TXT << "Array is destructed" << std::endl << DEFAULT_TXT;
		delete[] _array;
	};

	// --------------OPERATOR OVERLOAD---------------

	Array &operator=(Array const &rhs) {
		if (this != &rhs) {
			delete[] _array;
			_size = rhs._size;
			if (_size > 0) {
				_array = new T[_size]();
				for (unsigned int i = 0; i < _size; i++) _array[i] = rhs._array[i];
			}
		}
		return *this;
	}

	T &operator[](unsigned int index) {
		if (index >= _size) throw IndexOutOfRangeException();
		return _array[index];
	}

	T const &operator[](unsigned int index) const {
		if (index >= _size) throw IndexOutOfRangeException();
		return _array[index];
	}

	// --------------GETTERS---------------
	unsigned int size() const { return _size; };

	// --------------NESTED CLASS---------------

	class IndexOutOfRangeException : public std::exception {
	   public:
		char const *what() const throw() { return "Index out of range!\n"; }
	};
};

#endif