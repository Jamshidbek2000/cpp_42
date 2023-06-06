#ifndef SHRUNNERYCREATIONFORM_HPP
	#define SHRUNNERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const & inputTarget);
		ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm();

		std::string	getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;

		static const int	requiredSignGrade = 145;
		static const int	requiredExecGrade = 137;
};





#endif