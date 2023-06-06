#include "../include/PresidentialPardonForm.hpp"

// PresidentialPardonForm

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", PresidentialPardonForm::requiredSignGrade), target("target")
{
	std::cout << GREEN_TXT
			<< "PresidentialPardonForm Default constructor is called"
			<< DEFAULT_TXT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & inputTarget) :  AForm("PresidentialPardonForm", PresidentialPardonForm::requiredSignGrade), target(inputTarget)
{
	std::cout << GREEN_TXT
			<< "PresidentialPardonForm "
			<< target << ", parametric constructor is called"
			<< DEFAULT_TXT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) : AForm(rhs)
{
	target = rhs.target;
	std::cout << GREEN_TXT
			<< "PresidentialPardonForm "
			<< target << ", copy constructor is called"
			<< DEFAULT_TXT << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BLUE_TXT
			<< "PresidentialPardonForm " << target << ", destructor is called"
			<< DEFAULT_TXT << std::endl;
}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

std::string	PresidentialPardonForm::getTarget() const
{
	return target;
}

// ************************************************************************** //
//                               OPERATOR OVERWRITING                         //
// ************************************************************************** //

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
	{
		target = rhs.target;
		AForm::operator=(rhs);
	}
	std::cout << ORANGE_TXT
			<< "PresidentialPardonForm " << target << ", assignment operator is called"
			<< DEFAULT_TXT << std::endl;
	return *this;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false)
		throw(AForm::FormIsNotSignedException());
	if (executor.getGrade() > getRequiredGrade())
		throw (AForm::LowGradeToExecuteException());
	std::cout << target << " was pardonned by Zafod Beeblebrox" << std::endl;
}
