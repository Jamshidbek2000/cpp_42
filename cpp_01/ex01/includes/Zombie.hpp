#ifndef ZOMBIE_HPP
#	define ZOMBIE_HPP

#include <iostream>

#define SIZE 5

class	Zombie{
private:
	std::string _name;

public:
	Zombie(void);
	~Zombie(void);
	Zombie(std::string name);

	void	set_name(std::string name);
	void	announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif