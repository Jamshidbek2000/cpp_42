#include "../include/Character.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/IMateriaSource.hpp"
#include "../include/MateriaSource.hpp"

void	test4()
{
	MateriaSource	library1;
	MateriaSource	library2;

	library1.learnMateria(new Ice()); // ice has been added to the library

	AMateria*	materia = NULL;
	materia = library1.createMateria("ice"); // ice materia has been created

	delete materia;
	materia = NULL;

	materia = library2.createMateria("ice"); // ice materia has not been found!
	delete materia;
	library2 = library1;
	materia = library2.createMateria("ice"); // ice materia has been created
	delete materia;

	MateriaSource	library3(library1);
	library1.learnMateria(new Cure()); // cure has been added to the library

	materia = library3.createMateria("cure"); // cure materia has not been found!
	delete materia;
	materia = library1.createMateria("cure"); // cure materia has been created
	delete materia;
}

void	test3()
{
	Character*	soldier = new Character("Soldier");
	Character	copral(*soldier);
	Character	enemy("Enemy1");
	Character	enemy2("Enemy2");

	soldier->equip(new Ice());
	soldier->use(0, enemy);
	copral.use(0, enemy);

	enemy2.equip(new Cure());
	enemy2.use(0, enemy);

	enemy2 = enemy;
	enemy2.use(0, enemy);

	delete soldier;
}

void	test2()
{
	ICharacter*	yetti = new Character("Yetti");
	ICharacter*	magician = new Character("Magician");

	IMateriaSource*	yetti_library = new MateriaSource();
	IMateriaSource*	magician_library = new MateriaSource();

	yetti_library->learnMateria(new Ice());
	magician_library->learnMateria(new Cure());
	std::cout << std::endl;
	AMateria*	tmp_materia;

	tmp_materia = yetti_library->createMateria("cure");
	tmp_materia = yetti_library->createMateria("ice");
	yetti->equip(tmp_materia);
	std::cout << std::endl;

	tmp_materia = magician_library->createMateria("ice");
	tmp_materia = magician_library->createMateria("cure");
	magician->equip(tmp_materia);
	magician->equip(tmp_materia);
	std::cout << std::endl;

	yetti->use(1, *magician);
	yetti->use(0, *magician);
	magician->use(1, *magician);
	magician->use(0, *magician);
	std::cout << std::endl;

	Character*	magician2 = new Character("Magician2");
	*dynamic_cast<Character*>(magician2) = *dynamic_cast<Character*>(magician);
	magician2->equip(yetti_library->createMateria("ice"));
	magician2->use(0, *magician);
	magician2->use(1, *yetti);
	magician->use(0, *magician2);
	magician->use(1, *yetti);

	std::cout << std::endl;
	magician->unequip(1);
	magician->unequip(0);
	
	delete tmp_materia;

	delete yetti_library;
	delete magician_library;

	delete yetti;
	delete magician;
	delete magician2;
}

void	test1()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main( void )
{
	std::cout << std::endl << "\t\t\t\tTEST1" << std::endl;
	test1();
	std::cout << std::endl << "\t\t\t\tTEST2" << std::endl;
	test2();
	std::cout << std::endl << "\t\t\t\tTEST3" << std::endl;
	test3();
	std::cout << std::endl << "\t\t\t\tTEST4" << std::endl;
	test4();
	std::cout << std::endl;

	// system("leaks a.out");
	return (0); 
}
