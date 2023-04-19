#ifndef POINT_HPP
#	define POINT_HPP

#include "Fixed.hpp"

#define RIGHT 1
#define LEFT -1


class Point
{
private:
	Fixed	_x;
	Fixed	_y;

public:
	Point();
	~Point();
	Point(Fixed const x, Fixed const y);
	Point(Point const & rhs);

	Point& operator=(Point const & rhs);

	Fixed	get_x(void)const;
	Fixed	get_y(void)const;
	int		get_orientation_with_regards(Point const & a, Point const & b) const;
};




#endif