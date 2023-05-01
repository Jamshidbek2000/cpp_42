#ifndef DOG_HPP
#	define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*brain;

public:
	Dog();
	Dog(Dog const & rhs);
	virtual ~Dog();

	Dog&			operator=(Dog const & rhs);

	virtual void	make_sound() const;
	void			print_ideas()const;
	void			add_new_idea(std::string const & idea);
};

#endif