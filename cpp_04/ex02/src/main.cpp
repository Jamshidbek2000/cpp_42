#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include <sstream>

#define N 4

void	deep_copy_test()
{
	Cat	simba;
	Cat	tiger;
	for (int i = 0; i < N; i++)
	{
		std::ostringstream oss;
		oss << "Simba's idea #" << i;
		simba.add_new_idea(oss.str());
	}
	std::cout << std::endl;
	std::cout << "Simba: " << std::endl;
	simba.print_ideas();
	
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "Tiger: " << std::endl;
	tiger.print_ideas();

	std::cout << std::endl << std::endl;
	tiger = simba;

	std::cout << std::endl << std::endl;
	simba.add_new_idea("Simba's new idea");
	std::cout << "Simba: " << std::endl;
	simba.print_ideas();

	std::cout << std::endl;
	std::cout << "Tiger: " << std::endl;
	tiger.print_ideas();
	
	std::cout << std::endl << std::endl;
}

int main( void )
{
	// AAnimal	test;
	AAnimal* animals[N];

	std::cout << std::endl;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
	for (int i = 0; i < N; i++)
	{
		animals[i]->make_sound();
		delete animals[i];
		std::cout << std::endl;
	}

	// deep_copy_test();
	return (0); 
}
