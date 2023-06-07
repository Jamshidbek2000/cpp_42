#include "../include/Intern.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

Intern::Intern()
{
	std::cout << GREEN_TXT
			<< "Intern Default constructor is called"
			<< DEFAULT_TXT << std::endl;
}

Intern::Intern(Intern const& rhs)
{
	(void) rhs;
	std::cout << GREEN_TXT
			<< "Intern copy constructor is called"
			<< DEFAULT_TXT << std::endl;
}

Intern::~Intern()
{
	std::cout << BLUE_TXT
			<< "Intern destructor is called"
			<< DEFAULT_TXT << std::endl;
}

// ************************************************************************** //
//                               OPERATOR OVERWRITING                         //
// ************************************************************************** //

Intern& Intern::operator=(Intern const& rhs)
{
	(void) rhs;
	std::cout << ORANGE_TXT
			<< "Intern assignment operator is called"
			<< DEFAULT_TXT << std::endl;
	return *this;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

AForm* Intern::makeForm(std::string const & name, std::string const & target) const
{
	std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int i = 0;
	while (i < 3 && forms[i] != name)
		i++;
	AForm* form = NULL;
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::FormDoesNotExistException();
	}
	std::cout << "Intern created " << name << std::endl;
	return form;
}

// ************************************************************************** //
//                               NESTED CLASS                                 //
// ************************************************************************** //

const char* Intern::FormDoesNotExistException::what() const throw()
{
	return "Such Form does not exist!\n";
}
