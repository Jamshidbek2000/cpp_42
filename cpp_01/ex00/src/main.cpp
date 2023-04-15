#include "../includes/Zombie.hpp"

int	main(void)
{
	//------------- STACK
	Zombie	stack1("Stack1");
	Zombie	stack2("Stack2");
	stack1.announce();
	stack2.announce();
	std::cout << std::endl;

	//------------- HEAP

	Zombie*	heap1 = newZombie("Heap1");
	Zombie*	heap2 = newZombie("Heap2");
	heap1->announce();
	heap2->announce();
	std::cout << std::endl;

	// ------------ STACK
	randomChump("Random Champ");
	std::cout << std::endl;

	delete heap2;
	delete heap1;
	return (0);
}
