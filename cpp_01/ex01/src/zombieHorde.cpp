#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	try
	{
		Zombie*	horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].set_name(name);
		return (horde);
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "Error: " << ba.what() << std::endl;	
	}
	return (NULL);
}
