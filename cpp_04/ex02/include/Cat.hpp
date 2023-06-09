#ifndef CAT_HPP
#	define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain	*brain;

public:
	Cat();
	Cat(Cat const & rhs);
	virtual ~Cat();

	Cat&			operator=(Cat const & rhs);

	virtual void	make_sound() const;
	void			print_ideas()const;
	void			add_new_idea(std::string const & idea);
};

#endif