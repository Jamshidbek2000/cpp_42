#include "../include/Brain.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

Brain::Brain() : index_to_add(0)
{
	std::cout << "Default Brain is constructed" << std::endl;
}

Brain::Brain(Brain const & rhs)
{
	std::cout << "Brain Copy constructor is called" << std::endl;
	*this = rhs;
}

Brain::~Brain()
{
	std::cout << "Brain is destructed" << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Brain&	Brain::operator=(Brain const & rhs)
{
	std::cout << "Brain Assignment operator is called" << std::endl;
	if (this != &rhs)
	{
		index_to_add = rhs.index_to_add;
		for (int i = 0; i < index_to_add; i++)
			ideas[i] = rhs.ideas[i];
		for (int i = index_to_add; i < MAX_IDEAS; i++)
			ideas[i].clear();
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	Brain::add_new_idea(std::string const &idea)
{
	if (idea.empty())
	{
		std::cout << "Idea cannot be empty ;)" << std::endl;
		return ;
	}
	ideas[index_to_add] = idea;
	index_to_add = ++index_to_add % MAX_IDEAS;
}

void	Brain::print_ideas() const
{
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		if (ideas[i].empty())
			break;
		std::cout << "Idea #" << i << ": " << ideas[i] << std::endl;
	}
}
