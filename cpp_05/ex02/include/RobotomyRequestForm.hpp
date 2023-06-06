#ifndef RABOTOMYCREATIONFORM_HPP
	#define RABOTOMYCREATIONFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const & inputTarget);
		RobotomyRequestForm(RobotomyRequestForm const & rhs);
		RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm();

		std::string	getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;

		static const int	requiredSignGrade = 72;
		static const int	requiredExecGrade = 45;

		class RobotomyException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif