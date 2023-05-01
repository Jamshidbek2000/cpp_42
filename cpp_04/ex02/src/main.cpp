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
	Cat leo(simba);

	std::cout << std::endl << std::endl;
	simba.add_new_idea("Simba's new idea");
	std::cout << "Simba: " << std::endl;
	simba.print_ideas();

	std::cout << std::endl;
	std::cout << "Tiger: " << std::endl;
	tiger.print_ideas();

	std::cout << std::endl;
	std::cout << "Leo: " << std::endl;
	leo.print_ideas();
	leo.add_new_idea("Leo's new idea");

	std::cout << std::endl;
	std::cout << "Leo: " << std::endl;
	leo.print_ideas();
	
	std::cout << std::endl;
	std::cout << "Simba: " << std::endl;
	simba.print_ideas();

	std::cout << std::endl;
	std::cout << "Tiger: " << std::endl;
	tiger.print_ideas();

	std::cout << std::endl << std::endl;
}

void	test()
{
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
		delete animals[i];
		std::cout << std::endl;
	}
}

int main( void )
{
	std::cout << std::endl << "\t\t\t\tTEST1" << std::endl;
	test();
	std::cout << std::endl << "\t\t\t\tTEST2" << std::endl;
	deep_copy_test();
	std::cout << std::endl;

	return (0); 
}
