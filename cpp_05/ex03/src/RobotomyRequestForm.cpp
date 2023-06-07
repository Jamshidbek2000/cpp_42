#include "../include/RobotomyRequestForm.hpp"

// RobotomyRequestForm

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", RobotomyRequestForm::requiredSignGrade), target("target")
{
	std::cout << GREEN_TXT
			<< "RobotomyRequestForm Default constructor is called"
			<< DEFAULT_TXT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & inputTarget) : AForm("RobotomyRequestForm", RobotomyRequestForm::requiredSignGrade), target(inputTarget)
{
	std::cout << GREEN_TXT
			<< "RobotomyRequestForm "
			<< target << ", parametric constructor is called"
			<< DEFAULT_TXT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rhs) : AForm(rhs)
{
	target = rhs.target;
	std::cout << GREEN_TXT
			<< "RobotomyRequestForm "
			<< target << ", copy constructor is called"
			<< DEFAULT_TXT << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BLUE_TXT
			<< "RobotomyRequestForm " << target << ", destructor is called"
			<< DEFAULT_TXT << std::endl;
}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

std::string	RobotomyRequestForm::getTarget() const
{
	return target;
}

// ************************************************************************** //
//                               OPERATOR OVERWRITING                         //
// ************************************************************************** //

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
	{
		target = rhs.target;
		AForm::operator=(rhs);
	}
	std::cout << ORANGE_TXT
			<< "RobotomyRequestForm " << target << ", assignment operator is called"
			<< DEFAULT_TXT << std::endl;
	return *this;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int success;

	if (getIsSigned() == false)
		throw(AForm::FormIsNotSignedException());
	if (executor.getGrade() > getRequiredGrade())
		throw (AForm::LowGradeToExecuteException());
	std::srand(std::time(NULL));
	success = std::rand() % 2;
	std::cout << "< disturbing drilling noises >" << std::endl;
	if (success == 1)
		std::cout << target << " has been 50% robotomized" << std::endl;
	else
		throw (RobotomyRequestForm::RobotomyException());
}

// ************************************************************************** //
//                               NESTED CLASS                                 //
// ************************************************************************** //

const char* RobotomyRequestForm::RobotomyException::what() const throw()
{
	return "Robotomy failed!\n";
}
