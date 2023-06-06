#ifndef FORM_HPP
	#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const 	name;
		bool				isSigned;
		int			const	requiredGrade;

	public:
		AForm();
		AForm(std::string const & inputName, int inputRequiredGrade);
		AForm(AForm const & rhs);
		AForm & operator=(AForm const & rhs);
		virtual ~AForm();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getRequiredGrade() const;

		void		beSigned(Bureaucrat & bureaucrat);

		virtual void execute(Bureaucrat const & executor) const = 0;

		class FormIsNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class LowGradeToSignException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class LowGradeToExecuteException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream & os, AForm const & form);

#endif