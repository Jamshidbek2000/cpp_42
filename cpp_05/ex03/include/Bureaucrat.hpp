#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

class AForm;

class Bureaucrat
{
	private:
		std::string	const 	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const & inputName, int inputGrade);
		Bureaucrat(Bureaucrat const & rhs);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string const &	getName() const;
		int 				getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

		void				signForm(AForm & form);

		void				executeForm(AForm const & form);

		static const int	minGrade = 150;
		static const int	maxGrade = 1;


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
};

std::ostream& operator<<(std::ostream &os, Bureaucrat const & bureaucrat);

#endif