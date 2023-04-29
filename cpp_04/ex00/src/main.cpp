#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongDog.hpp"
#include "../include/WrongCat.hpp"

#define N 3

int main( void )
{
	// Correct way
	Animal*	animals[N];
	animals[0] = new Animal();
	animals[1] = new Cat();
	animals[2] = new Dog();

	std::cout << std::endl;
	for (size_t i = 0; i < N; i++)
		animals[i]->make_sound();


	// Wrong way
	std::cout << std::endl << std::endl;
	WrongAnimal*	wrong_animals[N];
	wrong_animals[0] = new WrongAnimal();
	wrong_animals[1] = new WrongCat();
	wrong_animals[2] = new WrongDog();

	std::cout << std::endl;
	for (size_t i = 0; i < N; i++)
		wrong_animals[i]->make_sound();	


	// Freeing
	std::cout << std::endl << std::endl;
	for (size_t i = 0; i < N; i++)
		delete animals[i];
	std::cout << std::endl;
	for (size_t i = 0; i < N; i++)
		delete wrong_animals[i];

	return (0); 

}
