#ifndef MATERIASOURCE_HPP
#	define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define LIB_SIZE  4

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_library[4];
public:
	MateriaSource();
	MateriaSource(AMateria* m);
	MateriaSource(MateriaSource const & rhs);
	~MateriaSource();

	MateriaSource& operator=(MateriaSource const & rhs);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif