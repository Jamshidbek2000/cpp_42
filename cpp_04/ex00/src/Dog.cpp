#include "../include/Dog.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog is contructed" << std::endl;
}

Dog::Dog(Dog const & rhs)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = rhs;
}

Dog::~Dog()
{
	std::cout << type << " is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Dog&	Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	Dog::make_sound() const
{
	std::cout << "Wuf" << std::endl;
}