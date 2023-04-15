#include "../includes/Zombie.hpp"

// void	leaks()
// {
// 	system("leaks horde");
// }

void	test()
{
	Zombie*	horde = zombieHorde(SIZE, "Bart");

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << i << " ";
		horde[i].announce();
	}

	delete [] horde;
}

int	main(void)
{
	test();
	// atexit(leaks);
	return (0);
}
