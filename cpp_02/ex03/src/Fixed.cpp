#include "../include/Fixed.hpp"

const int Fixed::_fractional_bits = 8;

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Fixed::Fixed() : _raw_bits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const raw_bits)
{
	// std::cout << "Int constructor called" << std::endl;
	_raw_bits = raw_bits << _fractional_bits;
}

Fixed::Fixed(float const raw_bits)
{
	// std::cout << "Float constructor called" << std::endl;
	_raw_bits = roundf(raw_bits * (1 << _fractional_bits));
}

Fixed::Fixed(Fixed const & rhs)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

// ************************************************************************** //
//                               SETTERS/GETTERS                              //
// ************************************************************************** //

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_raw_bits);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_raw_bits = raw;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

int	Fixed::toInt(void) const
{
	return (_raw_bits >> _fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return (float(_raw_bits) / (1 << _fractional_bits));
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_raw_bits = rhs.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_number)
{
	os << fixed_number.toFloat();
	return os;
}

// ARITHMETIC OPERATORS

Fixed Fixed::operator+(Fixed const & rhs) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	Fixed	result;
	result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> _fractional_bits);
	return (result);
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	Fixed	result;
	result.setRawBits((this->getRawBits() << _fractional_bits) / rhs.getRawBits());
	return (result);
}

// UNARY OPERATORS

Fixed Fixed::operator++(int)
{
	Fixed	before_incr(*this);

	_raw_bits++;
	return (before_incr);
}

Fixed& Fixed::operator++(void)
{
	_raw_bits++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	before_incr(*this);

	_raw_bits--;
	return (before_incr);
}

Fixed& Fixed::operator--(void)
{
	_raw_bits--;
	return (*this);
}

// ************************************************************************** //
//                               STATIC FUNCTIONS                             //
// ************************************************************************** //

Fixed&	Fixed::max(Fixed&a, Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

Fixed&	Fixed::min(Fixed&a, Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}
