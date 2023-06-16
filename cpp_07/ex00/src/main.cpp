#include "../include/Whatever.hpp"

class Awesome {
   public:
	Awesome(void) : _n(0) {}
	Awesome(int n) : _n(n) {}
	Awesome &operator=(Awesome &a) {
		_n = a._n;
		return *this;
	}
	bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
	bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
	bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
	bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
	bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
	bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
	int get_n() const { return _n; }

   private:
	int _n;
};
std::ostream &operator<<(std::ostream &o, const Awesome &a) {
	o << a.get_n();
	return o;
}

void myTest() {
	int a = -10;
	int b = 42;
	std::cout << YELLOW_TXT << "--------------INT--------------" << DEFAULT_TXT << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << YELLOW_TXT << "--------------STRING--------------" << DEFAULT_TXT << std::endl;
	std::string c = "hello";
	std::string d = "world";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << YELLOW_TXT << "---------------FLOAT-------------" << DEFAULT_TXT << std::endl;

	float floatA = 6.1;
	float floatB = 3.14;

	std::cout << "floatA: " << floatA << std::endl;
	std::cout << "floatB: " << floatB << std::endl;
	std::cout << "To swap<float>(floatA, floatB)" << std::endl;
	::swap<float>(floatA, floatB);
	std::cout << "floatA: " << floatA << std::endl;
	std::cout << "floatB: " << floatB << std::endl;

	std::cout << BLUE_TXT << "Explicit:" << DEFAULT_TXT << std::endl;
	std::cout << "min<float>(floatA, floatB): " << ::min<float>(floatA, floatB) << std::endl;
	std::cout << "max<float>(floatA, floatB): " << ::max<float>(floatA, floatB) << std::endl;

	std::cout << GREEN_TXT << "Implicit:" << DEFAULT_TXT << std::endl;
	std::cout << "min(floatA, floatB): " << ::min(floatA, floatB) << std::endl;
	std::cout << "max(floatA, floatB): " << ::max(floatA, floatB) << std::endl;

	std::cout << YELLOW_TXT << "---------------DOUBLE-------------" << DEFAULT_TXT << std::endl;

	double doubleA = 1234.56;
	double doubleB = -123.01;

	std::cout << "doubleA: " << doubleA << std::endl;
	std::cout << "doubleB: " << doubleB << std::endl;
	std::cout << "To swap<double>(doubleA, doubleB)" << std::endl;
	::swap<double>(doubleA, doubleB);
	std::cout << "doubleA: " << doubleA << std::endl;
	std::cout << "doubleB: " << doubleB << std::endl;

	std::cout << BLUE_TXT << "Explicit:" << DEFAULT_TXT << std::endl;
	std::cout << "min<double>(doubleA, doubleB): " << ::min<double>(doubleA, doubleB) << std::endl;
	std::cout << "max<double>(doubleA, doubleB): " << ::max<double>(doubleA, doubleB) << std::endl;

	std::cout << GREEN_TXT << "Implicit:" << DEFAULT_TXT << std::endl;
	std::cout << "min(doubleA, doubleB): " << ::min(doubleA, doubleB) << std::endl;
	std::cout << "max(doubleA, doubleB): " << ::max(doubleA, doubleB) << std::endl;
}

void test42() {
	Awesome a(2), b(4);

	swap(a, b);
	std::cout << a << " " << b << std::endl;
	std::cout << max(a, b) << std::endl;
	std::cout << min(a, b) << std::endl;
}

int main() {
	myTest();
	test42();


	return 0; }