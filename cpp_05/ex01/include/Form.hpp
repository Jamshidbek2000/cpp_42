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

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class LowGradeToSignException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormIsAlreadySigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream & os, Form const & form);

#endif