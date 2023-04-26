#ifndef BRAIN_HPP
#	define BRAIN_HPP

#include <iostream>

#define MAX_IDEAS 100

class Brain
{
private:
int			index_to_add;
protected:
std::string ideas[MAX_IDEAS];

public: 
	Brain();
	Brain(Brain const & rhs);
	~Brain();

	Brain & operator=(Brain const &rhs);

	void	print_ideas()const;
	void	add_new_idea(std::string const & idea);
};



#endif