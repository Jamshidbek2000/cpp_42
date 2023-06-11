#include <iostream>

class Parent {public: virtual ~Parent(){}};
class Child1 : public Parent {};
class Child2 : public Parent {};

class Unrelated {};

int	main()
{
	Child1	a;

	Parent	*b = &a;

	Child1	*c = dynamic_cast<Child1 *>(b);
	if (c == NULL)
		std::cout << "NOT OKEY 1" << std::endl;
	else
		std::cout << "OKEY 1" << std::endl;
	
	try
	{
		Child2 & d = dynamic_cast<Child2 &>(*b);
		std::cout << "OKEY 2" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		std::cout << "NOT OKEY 2" << std::endl;
		std::cerr << e.what() << '\n';
	}

	return 0;
}