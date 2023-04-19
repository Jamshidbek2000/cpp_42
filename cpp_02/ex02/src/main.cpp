#include "../include/Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	// std::cout << std::endl << "Pre incrementing a" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;

	// std::cout << std::endl << "Post incrementing a" << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;

	// std::cout << std::endl << "Final values: a b" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	// std::cout << std::endl << "Max (a, b): " << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0); 
}
