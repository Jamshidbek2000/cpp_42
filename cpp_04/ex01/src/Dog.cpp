#include "../include/Dog.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Dog::Dog() : Animal("Dog")
{
	brain = new Brain();
	std::cout << "Dog is constructed" << std::endl;
}

Dog::Dog(Dog const & rhs) : Animal(rhs)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = NULL;
	*this = rhs;
}

Dog::~Dog()
{
	delete brain;
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
		delete brain;
		brain = new Brain(*rhs.brain);
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

void	Dog::print_ideas() const
{
	brain->print_ideas();
}

void	Dog::add_new_idea(std::string const & idea)
{
	brain->add_new_idea(idea);
}
