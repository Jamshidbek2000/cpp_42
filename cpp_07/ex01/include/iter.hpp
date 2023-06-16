#ifndef ITER_HPP
#define ITER_HPP

#include <cctype>
#include <iostream>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

template <typename T, typename Function>
void iter(T *array, int arraySize, Function func) {
	for (int i = 0; i < arraySize; i++) {
		func(array[i]);
	}
}

template <typename T>
void myPrint(T &element) {
	std::cout << element << " ";
}

template <typename T>
void square(T &element) {
	element *= element;
}

template <typename T>
void increment(T &element) {
	element++;
}


#endif