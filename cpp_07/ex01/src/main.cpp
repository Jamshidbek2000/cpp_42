#include <string>

#include "../include/iter.hpp"

#define SIZE 11

void myToUpper(std::string& str) {
	for (unsigned int i = 0; i < str.size(); i++) {
		str.at(i) = std::toupper(str.at(i));
	}
}

class Awesome {
   public:
	Awesome(void) : _n(42) { return; }
	int get(void) const { return this->_n; }

   private:
	int _n;
};

std::ostream& operator<<(std::ostream& o, Awesome const& rhs) {
	o << rhs.get();
	return o;
}

template <typename T>
void print(T& x) {
	std::cout << x << std::endl;
	return;
}

void myTest() {
	int array[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	iter(array, SIZE, myPrint<int>);
	std::cout << std::endl;
	iter(array, SIZE, square<int>);
	iter(array, SIZE, myPrint<int>);
	std::cout << std::endl;
	iter(array, SIZE, increment<int>);
	iter(array, SIZE, myPrint<int>);

	std::cout << std::endl;
	std::string strs[2] = {"hello", "world"};
	iter(strs, 2, myToUpper);
	iter(strs, 2, myPrint<std::string>);

	std::cout << std::endl;
}

void test42() {
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print<const int>);
	iter(tab2, 5, print<Awesome>);
}

int main() {
	myTest();
	test42();

	return 0;
}