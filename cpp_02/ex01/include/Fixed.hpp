#ifndef FIXED_HPP
#	define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	static const int 	_fractional_bits;
	int					_value;
public:
	Fixed();
	~Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const & rhs);

	Fixed& operator=(Fixed const & rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float 	toFloat( void ) const;
	int 	toInt( void ) const;
};

	std::ostream& operator<<(std::ostream& os, const Fixed& fixed_number);

#endif