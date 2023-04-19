#ifndef FIXED_HPP
#	define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	static const int 	num_fractional_bits;
	int					_value;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const & rhs);
	Fixed& operator=(Fixed const & rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};



#endif