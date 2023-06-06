#ifndef FORM_HPP
	#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const 	name;
		bool				isSigned;
		int			const	requiredGrade;

		Form();
	public:
		Form(std::string const & inputName, int inputRequiredGrade);
		Form(Form const & rhs);
		Form & operator=(Form const & rhs);
		~Form();

		std::string	getName();
		bool		getIsSigned();
		int			getRequiredGrade();

		void		beSigned(Bureaucrat & bureaucrat);
};

std::ostream& operator<<(std::ostream & os, Form const & form);

#endif