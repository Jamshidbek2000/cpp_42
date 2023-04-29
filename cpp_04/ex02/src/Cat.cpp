#include "../include/Cat.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Cat::Cat() : AAnimal("Cat")
{
	brain = new Brain();
	std::cout << "Cat is contructed" << std::endl;
}

Cat::Cat(Cat const & rhs) : AAnimal(rhs)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = rhs;
}

Cat::~Cat()
{
	delete brain;
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
		delete brain;
		brain = new Brain(*rhs.brain);
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

void	Cat::print_ideas() const
{
	brain->print_ideas();
}

void	Cat::add_new_idea(std::string const & idea)
{
	brain->add_new_idea(idea);
}
