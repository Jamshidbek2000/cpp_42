#include "../include/MateriaSource.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS/DESCTRUCTORS                    //
// ************************************************************************** //

MateriaSource::MateriaSource()
{
	// std::cout << "Default MateriaSource is constructed" << std::endl;
	for (int i = 0; i < LIB_SIZE; i++)
		_library[i] = NULL;
	
}

MateriaSource::MateriaSource(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Empty MateriaSource is constructed because Materia provided is empty!" << std::endl;
		for (int i = 0; i < LIB_SIZE; i++)
			_library[i] = NULL;
	}
	else
	{
		// std::cout << "MateriaSource is constructed with " << m->getType() << std::endl;
		_library[0] = m;
		for (int i = 1; i < LIB_SIZE; i++)
			_library[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & rhs)
{
	// std::cout << "Copy constructor is called" << std::endl;
	for (int i = 0; i < LIB_SIZE; i++)
		_library[i] = NULL;
	*this = rhs;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource is destrected" << std::endl;
	for (int i = 0; i < LIB_SIZE; i++)
		delete _library[i];	
}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

MateriaSource& MateriaSource::operator=(MateriaSource const & rhs)
{
	// std::cout << "MateriaSource assignment operator is called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < LIB_SIZE; i++)
		{
			if (_library[i] != NULL)
				delete _library[i];
			if (rhs._library[i] != NULL)
				_library[i] = rhs._library[i]->clone();
			else
				_library[i] = NULL;
		}
	}
	return (*this);
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Provided Materia is NULL" << std::endl;
		return ;
	}
	for (int i = 0; i < LIB_SIZE; i++)
	{
		if (_library[i] == NULL)
		{
			std::cout << m->getType() << " has been added to the library" << std::endl;
			_library[i] = m;
			return ;
		}
	}
	std::cout << "Library is already full!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < LIB_SIZE; i++)
	{
		if (_library[i] != NULL
			&& _library[i]->getType().compare(type) == 0)
		{
			std::cout << type << " materia has been created" << std::endl;
			return (_library[i]->clone());
		}
	}
	std::cout << type << " materia has not been found!" << std::endl;
	return (NULL);
}
