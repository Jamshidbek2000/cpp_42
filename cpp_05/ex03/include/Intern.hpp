#ifndef INTERN_HPP
	#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(Intern const& rhs);
		Intern& operator=(Intern const& rhs);
		~Intern();
	
		AForm* makeForm(std::string const& name, std::string const& target) const;

		class FormDoesNotExistException : public std::exception
		{
			public:
				virtual const char* what() const throw();
  		};

};

#endif