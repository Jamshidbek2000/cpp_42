#ifndef FIXED_HPP
#	define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	static const int 	_fractional_bits;
	int					_raw_bits;
public:
	Fixed();
	~Fixed();
	Fixed(int const raw_bits);
	Fixed(float const raw_bits);
	Fixed(Fixed const & rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float 	toFloat( void ) const;
	int 	toInt( void ) const;

	Fixed& operator=(Fixed const & rhs);

	Fixed operator+(Fixed const& rhs) const;
	Fixed operator-(Fixed const& rhs) const;
	Fixed operator*(Fixed const& rhs) const;
	Fixed operator/(Fixed const& rhs) const;

	Fixed operator++(int);
	Fixed& operator++(void);
	Fixed operator--(int);
	Fixed& operator--(void);

	static Fixed&			max(Fixed& a, Fixed& b);
	static Fixed const &	max(Fixed const & a, Fixed const & b);
	static Fixed&			min(Fixed& a, Fixed& b);
	static Fixed const &	min(Fixed const & a, Fixed const & b);
};

	std::ostream& operator<<(std::ostream& os, const Fixed& fixed_number);

#endif