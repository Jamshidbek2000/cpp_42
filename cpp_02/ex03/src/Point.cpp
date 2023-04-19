#include "../include/Point.hpp"

Point::Point() : _x(0), _y(0)
{
	// std::cout << _x << std::endl; // DEL
	// std::cout << _y << std::endl;
}

Point::~Point(){}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
	// std::cout << _x << std::endl;
	// std::cout << _y << std::endl;
}

Point::Point(Point const & rhs)
{
	*this = rhs;
}

Point& Point::operator=(Point const & rhs)
{
	if (this != & rhs)
	{
		_x = rhs.get_x();
		_y = rhs.get_y();
	}
	return (*this);
}

Fixed	Point::get_x(void) const
{
	return (_x);
}

Fixed	Point::get_y(void) const
{
	return (_y);
}

int	Point::get_orientation_with_regards(Point const & a, Point const & b) const
{
	Point	vector_ab(a.get_x() - b.get_x(), a.get_y() - b.get_y());
	Point	vector_ap(a.get_x() - get_x(), a.get_y() - get_y());
	float	cross_product;

	cross_product = (vector_ab.get_x() * vector_ap.get_y() - vector_ab.get_y() * vector_ap.get_x()).toFloat();
	
	if (cross_product > 0)
		return (LEFT);
	return (RIGHT);
}
