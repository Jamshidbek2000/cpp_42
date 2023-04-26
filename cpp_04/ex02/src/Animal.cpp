#include "../include/Animal.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Animal::Animal() : type("Animal")
{
	std::cout << "Default Animal" << " is contructed" << std::endl;
}

Animal::Animal(std::string const & type) : type(type)
{
	std::cout << type << " Animal is contructed" << std::endl;
}

Animal::Animal(Animal const & rhs)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = rhs;
}

Animal::~Animal()
{
	std::cout << type << " type Animal is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Animal&	Animal::operator=(Animal const & rhs)
{
	std::cout << "Animal assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	Animal::make_sound() const
{
	std::cout << "Animal sound" << std::endl;
}
