#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

template <typename T>
void swap(T& t1, T& t2) {
	T tmp;

	tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template <typename T>
T const& max(T const& t1, T const& t2) {
	return (t1 > t2) ? t1 : t2;
}

template <typename T>
T const& min(T const& t1, T const& t2) {
	return (t1 < t2) ? t1 : t2;
}

#endif