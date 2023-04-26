#include "../include/Cat.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat is contructed" << std::endl;
}

Cat::Cat(Cat const & rhs)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = rhs;
}

Cat::~Cat()
{
	std::cout << type << " is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Cat&	Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	Cat::make_sound() const
{
	std::cout << "Meow" << std::endl;
}