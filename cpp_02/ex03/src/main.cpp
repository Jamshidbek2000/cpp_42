#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

bool	bsp(Point const & point, Point const & a, Point const & b, Point const & c);

int main( void )
{
	Point p1(4.5f, 3.5f);
	Point a1(1.0f, 1.0f);
	Point b1(7.0f, 1.0f);
	Point c1(4.0f, 6.0f);
	std::cout << "Result: " << bsp(p1, a1, b1, c1) << std::endl;

	Point p2(8.0f, 3.0f);
	Point a2(1.0f, 1.0f);
	Point b2(7.0f, 1.0f);
	Point c2(4.0f, 6.0f);
	std::cout << "Result: " << bsp(p2, a2, b2, c2) << std::endl;

	Point p3(4.5f, 3.5f);
	Point a3(1.0f, 1.0f);
	Point b3(7.0f, 1.0f);
	Point c3(4.0f, 6.0f);
	std::cout << "Result: " << bsp(p3, a3, b3, c3) << std::endl;

	Point p4(2.0f, 2.0f);
	Point a4(1.0f, 1.0f);
	Point b4(7.0f, 1.0f);
	Point c4(4.0f, 6.0f);
	std::cout << "Result: " << bsp(p4, a4, b4, c4) << std::endl;

	return (0); 
}

bool	bsp(Point const & point, Point const & a, Point const & b, Point const & c)
{
	int orient1 = point.get_orientation_with_regards(a, b);
	int orient2 = point.get_orientation_with_regards(b, c);
	int orient3 = point.get_orientation_with_regards(c, a);

	if (orient1 != orient2 || orient1 != orient3)
		return (false);
	return (true);
}
